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

#include "HTTPServer.h"

#include <QString>
#include <QTcpSocket>
#include <QHostAddress>
#include <QHttpRequestHeader>

#include "../../Response.h"
#include "../../Request.h"
#include "../../Resource/Resource.h"
#include "../../Resource/Representation.h"

namespace Nanogear {
namespace Concrete {
namespace HTTP {


HTTPServer::HTTPServer(int port, QObject* parent) : Server(port, parent) {
    connect(&m_tcpServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

void HTTPServer::start() {
    qDebug() << Q_FUNC_INFO << "started on " << QHostAddress::Any << ":" << listenPort();
    m_tcpServer.listen(QHostAddress::Any, listenPort());
}

void HTTPServer::onNewConnection() {
    qDebug() << Q_FUNC_INFO << "received new connection";
    QTcpSocket* client = m_tcpServer.nextPendingConnection();
    connect(client, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
    connect(client, SIGNAL(disconnected()), client, SLOT(deleteLater()));
}

void HTTPServer::onClientReadyRead() {
    qDebug() << Q_FUNC_INFO << "ready to read data sent by the client";

    QTcpSocket* client = static_cast<QTcpSocket*>(sender());
    qDebug() << Q_FUNC_INFO << "request size:" << client->size();

    QByteArray inputBlock(client->readAll());

    QHttpRequestHeader requestHeader(inputBlock);
    Context requestPath = requestHeader.path();
    ClientInfo clientInfo(requestHeader.value("user-agent"));

    /* add media types */ {
        QList< Preference<MediaType> > accept;
        foreach (const QString& mediaType, requestHeader.value("accept").split(", ")) {
            QList<QString> pair = mediaType.split(';');
            accept.append(Preference<MediaType>(pair.at(0), pair.value(1, "1").toFloat()));
        }
    }
    qDebug() << Q_FUNC_INFO << "requested path == " << requestHeader.path();
    qDebug() << Q_FUNC_INFO << "requested context == " << requestPath.path();

    Resource::Resource* resource = findChild<Resource::Resource*>(requestPath.path());
    Request request(requestHeader.method(), requestPath, clientInfo);
    Response response = resource->handleRequest(request);

    QHttpResponseHeader responseHeader(response.status().code(), response.status().name(),
        requestHeader.majorVersion(), requestHeader.minorVersion());
    responseHeader.setContentType(response.representation()->mediaType());

    client->write(responseHeader.toString().toUtf8());
    client->write(response.representation()->asByteArray());
    client->close();
}


}
}
}
