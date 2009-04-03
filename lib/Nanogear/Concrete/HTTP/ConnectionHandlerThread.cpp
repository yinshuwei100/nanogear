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

#include <QString>
#include <QTcpSocket>
#include <QHostAddress>
#include <QHttpRequestHeader>
#include <QTextCodec>

#include "HTTPServer.h"
#include "Utility.h"

#include "../../Response.h"
#include "../../Request.h"
#include "../../Method.h"
#include "../../Resource/Resource.h"
#include "../../Resource/Representation.h"

namespace Nanogear {
namespace Concrete {
namespace HTTP {

ConnectionHandlerThread::~ConnectionHandlerThread() {
    qDebug() << Q_FUNC_INFO << "Thread stopped";
}

void ConnectionHandlerThread::run() {
    qDebug() << Q_FUNC_INFO << "New thread started";

    m_clientSocket = m_server->tcpServer()->nextPendingConnection();
    if (!m_clientSocket) {
        qDebug() << Q_FUNC_INFO << "Socket error" << m_clientSocket->errorString();
        deleteLater();
        return;
    }

    connect(m_clientSocket, SIGNAL(readyRead()), SLOT(onClientReadyRead()));
    connect(m_clientSocket, SIGNAL(disconnected()), SLOT(quit()));
    connect(this, SIGNAL(finished()), SLOT(deleteLater()));
    connect(this, SIGNAL(finished()), m_clientSocket, SLOT(deleteLater()));
}

void ConnectionHandlerThread::onClientReadyRead() {
    qDebug() << Q_FUNC_INFO << "Handling request (size:" << m_clientSocket->size() << ")";

    // Separate the HTTP headers from the request body (if any)
    QByteArray rawRequestHeader;
    for (;;) {
        QByteArray line = m_clientSocket->readLine();
        if (line == "\r\n")
            break;
        rawRequestHeader += line;
    }

    QHttpRequestHeader requestHeader(rawRequestHeader);

    // Fill Context and Method by using informations supplied by
    // the client
    Context requestPath(requestHeader.path());
    Nanogear::Method requestedMethod(requestHeader.method().toUpper());

    // Fill the request body, if needed
    QByteArray requestBody;
    if (requestHeader.hasKey("content-length"))
        requestBody = m_clientSocket->read(requestHeader.value("content-length").toLongLong());
    else if (requestedMethod.hasBody())
        requestBody = m_clientSocket->readAll();

    // Fill the ClientInfo object
    PreferenceList<MimeType> acceptedMimeTypes = getPreferenceListFromHeader<MimeType>(requestHeader.value("accept"));
    PreferenceList<QLocale> acceptedLocales = getPreferenceListFromHeader<QLocale>(requestHeader.value("accept-language"));
    PreferenceList<QTextCodec*> acceptedCharsets = getPreferenceListFromHeader<QTextCodec*>(requestHeader.value("accept-charset"));
    ClientInfo clientInfo(acceptedMimeTypes, acceptedLocales, acceptedCharsets, requestHeader.value("user-agent"));

    qDebug() << Q_FUNC_INFO << "requested path == " << requestHeader.path();
    qDebug() << Q_FUNC_INFO << "requested context == " << requestPath.path();

    // Find a matching resource in Qt MetaObject hierarchy
    Resource::Resource* resource = m_server->findChild<Resource::Resource*>(requestPath.path());

    // Build the request object
    Request request(requestHeader.method(), requestPath, clientInfo, requestBody);

    // And retrieve the response object (if the resource cannot be found just)
    // return a default response object
    Response response = resource ? resource->handleRequest(request) :
        Application::instance()->notFound(request);

    const Resource::Representation* representation = response.representation();

    QTextCodec* codec = clientInfo.acceptedTextCodecs().top();

    QHttpResponseHeader responseHeader(response.status().toType(), response.status().toString(),
        requestHeader.majorVersion(), requestHeader.minorVersion());
    responseHeader.setValue("connection", requestHeader.value("connection"));
    if (responseHeader.value("connection").isEmpty()) {
        if (responseHeader.majorVersion() <= 1 && responseHeader.minorVersion() == 0)
            responseHeader.setValue("connection", "close");
    }
    responseHeader.setValue("server", "Nanogear");

    if (response.expirationDate().isValid())
        responseHeader.setValue("expires", response.expirationDate().toUTC().toString("dd MMM yyyy ss:mm:hh") + " GMT");

    responseHeader.setContentType(representation->format(clientInfo.acceptedMimeTypes()).toString());

    QByteArray responseData(representation->data(clientInfo.acceptedMimeTypes()));
    responseHeader.setValue("content-length", QString::number(responseData.length()));

    // And finally send data back to the client
    qDebug() << Q_FUNC_INFO << "sending data back to the client (size:" << responseHeader.value("content-length") << ")";
    m_clientSocket->write(responseHeader.toString().toUtf8());
    m_clientSocket->write(responseData);

    if (responseHeader.value("connection") == "close") {
        qDebug() << Q_FUNC_INFO << "disconnecting from host";
        m_clientSocket->disconnectFromHost();
        m_clientSocket->waitForDisconnected();
    } else {
        qDebug() << Q_FUNC_INFO << "using a persistent connection (" << responseHeader.value("connection") << ").";
        m_clientSocket->waitForReadyRead(-1);

        qDebug() << Q_FUNC_INFO << "Reusing existing thread";
        onClientReadyRead();
    }
}

}
}
}
