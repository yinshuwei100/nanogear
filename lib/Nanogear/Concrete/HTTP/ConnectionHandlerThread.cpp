/*
 * Nanogear - C++ web development framework
 *
 * This library is based on Restlet (R) <http://www.restlet.org> by Noelios Technologies
 * Copyright (C) 2005-2008 by Noelios Technologies <http://www.noelios.com>
 * Restlet is a registered trademark of Noelios Technologies. All other marks and
 * trademarks are property of their respective owners.
 *
 * Copyright (C) 2008-2009 Lorenzo Villani.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ConnectionHandlerThread.h"

#include <QUrl>
#include <QPair>
#include <QString>
#include <QTcpSocket>
#include <QHostAddress>
#include <QHttpRequestHeader>
#include <QLocale>
#include <QTextCodec>
#include <QDateTime>
#include <QTcpServer>

#include "HTTPServer.h"
#include "Utility.h"

#include "../../Response.h"
#include "../../Request.h"
#include "../../Method.h"
#include "../../ClientInfo.h"
#include "../../Status.h"
#include "../../Resource/Resource.h"
#include "../../Resource/Representation.h"

namespace Nanogear {
namespace Concrete {
namespace HTTP {


void ConnectionHandlerThread::run() {
    qDebug() << Q_FUNC_INFO << "New thread started";

    qDebug() << Q_FUNC_INFO << "Socket descriptor: " << m_socketHandle;
    if (!m_clientSocket.setSocketDescriptor(m_socketHandle)) {
        qDebug() << Q_FUNC_INFO << "Failed to set socked descriptor";
        deleteLater();
        return;
    }

    connect(&m_clientSocket, SIGNAL(disconnected()), this, SLOT(quit()));
    connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
    connect(this, SIGNAL(finished()), &m_clientSocket, SLOT(deleteLater()));

    m_clientSocket.waitForReadyRead(-1);

    qDebug() << Q_FUNC_INFO << "Handling request (size:"
        << m_clientSocket.size() << ")";



    /* ***************************************************************
     * This part of the method is dedicated to fill the Request object
     * ***************************************************************/
    // Separate the HTTP headers from the request body (if any)
    QByteArray rawRequestHeader;
    for (;;) {
        QByteArray line = m_clientSocket.readLine();
        if (line == "\r\n")
            break;
        rawRequestHeader += line;
    }

    QHttpRequestHeader requestHeader(rawRequestHeader);
    qDebug() << Q_FUNC_INFO << "Requested path: " << requestHeader.path();

    // Fill Method by using informations supplied by the client
    Nanogear::Method requestedMethod(requestHeader.method().toUpper());

    // Fill the request body, if needed
    QByteArray requestBody = requestHeader.hasKey("Content-Length")
        ? m_clientSocket.read(requestHeader.value("Content-Length").toLongLong()) : "";
    if (requestedMethod.hasBody())
        requestBody = m_clientSocket.readAll();
    Resource::Representation entity(requestBody, requestHeader.value("Content-Type"));

    PreferenceList<MimeType> acceptedMimeTypes(
        getPreferenceListFromHeader<MimeType>(requestHeader.value("Accept")));
    PreferenceList<QLocale> acceptedLocales(
        getPreferenceListFromHeader<QLocale>(requestHeader.value("Accept-Language")));
    PreferenceList<QTextCodec*> acceptedCharsets(
        getPreferenceListFromHeader<QTextCodec*>(requestHeader.value("Accept-Charset")));


    // Fill the ClientInfo object
    ClientInfo clientInfo(acceptedMimeTypes, acceptedLocales, acceptedCharsets,
        requestHeader.value("User-Agent"));
    

    // Extract the GET query string (if any)
    QUrl queryString(requestHeader.path());
    QHash<QString, QString> parameters;
    
    // This is just a way to overcome the fact Q_FOREACH is a two-args macro...
    typedef QPair<QByteArray, QByteArray> KeyValuePair;
    foreach (const KeyValuePair& keyValue, queryString.encodedQueryItems()) {
        parameters[keyValue.first] = keyValue.second;
    }

    // Handle POST query string
    if (entity.hasFormat("application/x-www-form-urlencoded")) {
        qDebug() << Q_FUNC_INFO << entity.data("application/x-www-form-urlencoded");
        /*foreach (const KeyValuePair& keyValue, formData.encodedQueryItems()) {
            parameters[keyValue.first] = keyValue.second;
        }*/
    }
    
    
    Request request(requestHeader.method(), clientInfo, &entity);
    request.setResourceRef(queryString.path());
    request.setParameters(parameters);


    /* ***************************************************************
     * Handle the request
     * ***************************************************************/
    // Let the Application's root() handle routing (if a Router class) or let
    // it respond at every uri, if needed
    qDebug() << Q_FUNC_INFO << "Handling the request";
    Response response;
    Application::instance()->root()->handleRequest(request, response);



    /* *******************************************************************
     * Extract data from the Response object and answer back to the client
     * *******************************************************************/
    // Retrieve the representation from the response
    const Resource::Representation* representation = response.representation();
    
    QTextCodec* codec = clientInfo.acceptedTextCodecs().top();
    Q_UNUSED(codec); /*!< @todo use this field */

    QHttpResponseHeader responseHeader(response.status().toType(), response.status().toString(),
        requestHeader.majorVersion(), requestHeader.minorVersion());
    responseHeader.setValue("Connection", requestHeader.value("Connection"));
    
    if (responseHeader.value("Connection").isEmpty()) {
        if (responseHeader.majorVersion() <= 1 && responseHeader.minorVersion() == 0)
            responseHeader.setValue("Connection", "close");
    }

    responseHeader.setValue("Server", "Nanogear");

    if (response.expirationDate().isValid()) {
        responseHeader.setValue("Expires", response.expirationDate().toUTC()
            .toString("dd MMM yyyy ss:mm:hh") + " GMT");
    }

    // If the resource provides only one representation send it anyway
    QByteArray responseData;
    if (representation != 0) {
        if (representation->formats().count() == 1) {
            responseHeader.setContentType(representation->formats().at(0));
            responseData = representation->data(representation->formats().at(0));
        } else {
            responseHeader.setContentType(representation->format(clientInfo.acceptedMimeTypes()).toString());
            responseData = representation->data(clientInfo.acceptedMimeTypes());
        }
    }
        
    responseHeader.setValue("Content-Length",
        QString::number(responseData.length()));

    // And finally send data back to the client
    qDebug() << Q_FUNC_INFO << "sending data back to the client (size:"
        << responseHeader.value("Content-Length") << ")";
    m_clientSocket.write(responseHeader.toString().toUtf8());
    m_clientSocket.write(responseData);

    qDebug() << Q_FUNC_INFO << "Waiting for data to be written";
    m_clientSocket.waitForBytesWritten(-1);

    qDebug() << Q_FUNC_INFO << "Disconnecting from host and destroying thread";
    m_clientSocket.disconnectFromHost();

    QThread::run();
}

}
}
}

