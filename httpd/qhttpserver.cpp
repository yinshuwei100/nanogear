/*
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include <QString>
#include <QDebug>
#include <QByteArray>
#include <QDataStream>
#include <QTcpSocket>
#include <QHttpHeader>

#include "qhttpserver.h"
#include "../lib/resource.h"


QHttpServer::QHttpServer(const QHostAddress& addr, int port) {
    connect(this, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    qDebug() << "Listening on " << addr.toString() << ":" << port;
    listen(addr, port);
}


void QHttpServer::onNewConnection() {
    QTcpSocket* client = this->nextPendingConnection();
    connect(client, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
    connect(client, SIGNAL(disconnected()), client, SLOT(deleteLater()));
}

void QHttpServer::onClientReadyRead() {
    QByteArray inputBlock;

    QTcpSocket* client = dynamic_cast<QTcpSocket*>(sender());
    inputBlock = client->readAll();
    QHttpRequestHeader requestHeader(inputBlock);
    qDebug() << "Requested path: " << requestHeader.path();

    foreach (QString pth, m_resources.keys()) {
        if (requestHeader.path() == pth) {
            qDebug() << "Found a resource at this URI";

            if (requestHeader.method() == "GET") {
                m_resources[pth]->doGet(requestHeader, client);
            } else if (requestHeader.method() == "POST") {
                m_resources[pth]->doPost(requestHeader, client);
            } else if (requestHeader.method() == "PUT") {
                m_resources[pth]->doPut(requestHeader, client);
            } else if (requestHeader.method() == "DELETE") {
                m_resources[pth]->doDelete(requestHeader, client);
            } else {
                //! @todo: should throw an exception
            }

            // No need to go further
            break;
        }
    }

    // Automatically close the socket
    client->close();
}


void QHttpServer::attachResource(const QString& path, Resource* res) {
    m_resources[path] = res;
}


