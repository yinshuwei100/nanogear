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
#include <QDateTime>
#include <QTcpServer>

#include "HTTPServer.h"
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

struct ConnectionHandlerThread::Private {
    Private(HTTPServer* s) : server(s) {}
    HTTPServer* server;
    QTcpSocket* clientSocket;
};

ConnectionHandlerThread::ConnectionHandlerThread(HTTPServer* server, QObject* parent)
    : QThread(parent), d(new Private(server)) {}
ConnectionHandlerThread::~ConnectionHandlerThread() {
    qDebug() << Q_FUNC_INFO << "Thread stopped";
    delete d;
}

void ConnectionHandlerThread::run() {
    qDebug() << Q_FUNC_INFO << "New thread started";
    d->clientSocket = d->server->tcpServer()->nextPendingConnection();
    if (!d->clientSocket) {
        qDebug() << Q_FUNC_INFO << "Socket error" << d->clientSocket->errorString();
        deleteLater();
        return;
    }
    connect(d->clientSocket, SIGNAL(readyRead()), SLOT(onClientReadyRead()));
    connect(d->clientSocket, SIGNAL(disconnected()), SLOT(quit()));
    connect(this, SIGNAL(finished()), SLOT(deleteLater()));
    connect(this, SIGNAL(finished()), d->clientSocket, SLOT(deleteLater()));
    QThread::run();
}

void ConnectionHandlerThread::onClientReadyRead() {
    qDebug() << Q_FUNC_INFO << "Handling request (size:" << d->clientSocket->size() << ")";
    QByteArray requestHeaderByteArray;
    for (;;) {
        QByteArray line = d->clientSocket->readLine();
        if (line == "\r\n")
            break;
        requestHeaderByteArray += line;
    }

    QHttpRequestHeader requestHeader(requestHeaderByteArray);
    Context requestPath = requestHeader.path();
    ClientInfo clientInfo(requestHeader.value("user-agent"));

    /* add mime types */ {
        Preference<MimeType>::List accept;
        foreach (const QString& mimeType, requestHeader.value("accept").remove(" ").split(",")) {
            QStringList pair = mimeType.split(";q=");
            accept.append(Preference<MimeType>(pair.at(0), pair.value(1, "1").toFloat()));
        }
        clientInfo.setAcceptedMimeTypes(accept);
    }
    /* add locales */ {
        Preference<QLocale>::List accept;
        foreach (const QString& locale, requestHeader.value("accept-language").remove(" ").split(",")) {
            QStringList pair = locale.split(";q=");
            accept.append(Preference<QLocale>(pair.at(0), pair.value(1, "1").toFloat()));
         }
         clientInfo.setAcceptedLocales(accept);
    }
    /* add text codecs */ {
        Preference<QTextCodec*>::List accept;
        foreach (const QString& codec, requestHeader.value("accept-charset").remove(" ").split(",")) {
            QStringList pair = codec.split(";q=");
            accept.append(Preference<QTextCodec*>(QTextCodec::codecForName(pair.at(0).toUtf8()), pair.value(1, "1").toFloat()));
        }
        clientInfo.setAcceptedTextCodecs(accept);
    }
    qDebug() << Q_FUNC_INFO << "requested path == " << requestHeader.path();
    qDebug() << Q_FUNC_INFO << "requested context == " << requestPath.path();
    Resource::Resource* resource = d->server->findChild<Resource::Resource*>(requestPath.path());
    Request request(requestHeader.method(), requestPath, clientInfo);
    if (requestHeader.hasKey("content-length"))
        request.setBody(d->clientSocket->read(requestHeader.value("content-length").toLongLong()));
    else if (request.method().hasBody())
        request.setBody(d->clientSocket->readAll());
    Response response = resource ? resource->handleRequest(request) : Application::instance()->notFound(request);
    const Resource::Representation* representation = response.representation();
    QTextCodec* codec = clientInfo.acceptedTextCodecs().top();
    QHttpResponseHeader responseHeader(response.status().toType(), response.status().toString(),
        requestHeader.majorVersion(), requestHeader.minorVersion());
    responseHeader.setValue("connection", requestHeader.value("connection"));
    responseHeader.setValue("server", "Nanogear");
    if (response.expires().isValid())
        responseHeader.setValue("expires", response.expires().toUTC().toString("dd MMM yyyy ss:mm:hh") + " GMT");
    responseHeader.setContentType(representation->format(clientInfo.acceptedMimeTypes()).toString());
    QByteArray responseData = representation->data(clientInfo.acceptedMimeTypes());
    responseHeader.setValue("content-length", QString::number(responseData.length()));
    qDebug() << Q_FUNC_INFO << "sending data back to the client (size:" << responseHeader.value("content-length") << ")";
    d->clientSocket->write(responseHeader.toString().toUtf8());
    d->clientSocket->write(responseData);
    if (responseHeader.value("connection") == "close") {
        qDebug() << Q_FUNC_INFO << "disconnecting from host";
        d->clientSocket->disconnectFromHost();
        d->clientSocket->waitForDisconnected();
    } else {
        qDebug() << Q_FUNC_INFO << "using a persistent connection (" << responseHeader.value("connection") << ").";
        d->clientSocket->waitForReadyRead(-1);
        qDebug() << Q_FUNC_INFO << "Reusing existing thread";
        onClientReadyRead();
    }
}

}
}
}

