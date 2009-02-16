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

#include "httpserver.h"
#include "application.h"

HTTPServer::HTTPServer(int port) : Server(port) {
    connect(&m_tcpServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

void HTTPServer::start() {
    qDebug() << "HTTPServer: started on " << QHostAddress::Any << ":" << listenPort();
    m_tcpServer.listen(QHostAddress::Any, listenPort());
}

void HTTPServer::onNewConnection() {
    qDebug() << "HTTPServer: received new connection";
    QTcpSocket* client = m_tcpServer.nextPendingConnection();
    connect(client, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
    connect(client, SIGNAL(disconnected()), client, SLOT(deleteLater()));
}

void HTTPServer::onClientReadyRead() {
    qDebug() << "HTTPServer: ready to read data sent by the client";
    
    QByteArray inputBlock;

    QTcpSocket* client = dynamic_cast<QTcpSocket*>(sender());
    inputBlock = client->readAll();
    
    QHttpRequestHeader requestHeader(inputBlock);
    qDebug() << "HTTPServer: requested path: " << requestHeader.path();
    foreach (const QString& appContext, attachedApps().keys()) {
        if (requestHeader.path().startsWith(appContext)) {
            qDebug() << "HTTPServer: found an application within context " << appContext;
            
            // We pass the URIs without the context
            QString URI(requestHeader.path());
            URI.remove(0, appContext.size());
            qDebug() << "HTTPServer: passing " << URI;

            /*! @note
             * This is WRONG, the Uniform (or Uniform-derived) itself should be able to handle requests
             */
            // Get context
            Router* root = attachedApps()[appContext]->createRoot();
            foreach (const QString& mappedURI, root->mappedResources().keys()) {
                if (URI == mappedURI) {
                    //! @note Support only GET for now until I come up with a better design
                    if (requestHeader.method() == "GET") {
                        // Ouch!
                        // It's better to follow Restlet's design and move the
                        // context information within a Uniform-derived class
                        root->mappedResources()[mappedURI]->get(requestHeader, client);
                    }
                }
            }

            delete root;
        }
    }

    // Automatically close the socket
    client->close();
}


