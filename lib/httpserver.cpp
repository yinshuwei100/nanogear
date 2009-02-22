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
#include <QTcpSocket>
#include <QHostAddress>
#include <QHttpRequestHeader>

#include "router.h"
#include "resource.h"
#include "httpserver.h"
#include "application.h"

HTTPServer::HTTPServer(int port) : Server(port) {
    connect(&m_tcpServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

void HTTPServer::start() {
    qDebug() << Q_FUNC_INFO << " started on " << QHostAddress::Any << ":" << listenPort();
    m_tcpServer.listen(QHostAddress::Any, listenPort());
}

void HTTPServer::onNewConnection() {
    qDebug() << Q_FUNC_INFO << " received new connection";
    QTcpSocket* client = m_tcpServer.nextPendingConnection();
    connect(client, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
    connect(client, SIGNAL(disconnected()), client, SLOT(deleteLater()));
}

void HTTPServer::onClientReadyRead() {
    qDebug() << Q_FUNC_INFO << " ready to read data sent by the client";
    
    QByteArray inputBlock;

    QTcpSocket* client = static_cast<QTcpSocket*>(sender());
    inputBlock = client->readAll();
    
    QHttpRequestHeader requestHeader(inputBlock);
    qDebug() << "HTTPServer: requested path: " << requestHeader.path();
    foreach (Application* app, attachedApplications()) {
        if (requestHeader.path().startsWith(app->context().contextPath())) {
            qDebug() << Q_FUNC_INFO << " found an application within context " << app->context().contextPath();

            // Get context
            //! @note recreate root for each new request?
            Router* root = app->createRoot();
            
            foreach (Resource* resource, root->attachedResources()) {
                qDebug() << Q_FUNC_INFO << " resource context is: " << resource->context().contextPath();
                if (requestHeader.path() == resource->context().contextPath()) {
                    qDebug() << Q_FUNC_INFO << " found resource attached within this context";
                    // Set the response object
                    
                    //! @note Support only GET for now until I come up with a better design
                    if (requestHeader.method() == "GET") {
                        resource->handleGet();
                    }
                }
            }

            delete root;
        }
    }

    // Automatically close the socket
    client->close();
}


