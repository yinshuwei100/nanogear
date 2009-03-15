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

#include "../../Router.h"
#include "../../Response.h"
#include "../../Application.h"
#include "../../Resource/Resource.h"
#include "../../Resource/Representation.h"

namespace Nanogear {
namespace Concrete {
namespace HTTP {


HTTPServer::HTTPServer(int port) : Server(port) {
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
    
    QByteArray inputBlock;

    QTcpSocket* client = static_cast<QTcpSocket*>(sender());
    inputBlock = client->readAll();
    
    QHttpRequestHeader requestHeader(inputBlock);
    qDebug() << Q_FUNC_INFO << "requested path == " << requestHeader.path();
    
    foreach (Application* app, attachedApplications()) {
        if (requestHeader.path().startsWith(app->context().contextPath())) {
            qDebug() << Q_FUNC_INFO << "found an application within context " << app->context().contextPath();

            // Get context
            //! @note recreate root for each new request?
            Router* root = app->createRoot();
            Response response;
            
            foreach (Resource::Resource* resource, root->attachedResources()) {
                qDebug() << Q_FUNC_INFO << "resource context is: " << resource->context().contextPath();
                if (requestHeader.path() == resource->context().contextPath()) {
                    qDebug() << Q_FUNC_INFO << "found resource attached within this context";
                    // Begin by writing the response header
                    QHttpResponseHeader responseHeader(200, "OK", requestHeader.majorVersion(), requestHeader.minorVersion());

                    // Set the response object
                    resource->setResponse(response);

                    //! @note Support only GET for now until I come up with a better design
                    if (requestHeader.method() == "GET") {
                        resource->handleGet();
                        responseHeader.setContentType(resource->response().representation()->mediaType());
                        client->write(responseHeader.toString().toUtf8());
                        client->write(resource->response().representation()->asByteArray());
                    }

                    // Close the socket
                    client->close();
                    // only one resource per URI
                    break;
                }
            }
            
            // cleanup
            delete root;
        }
    }
}


}
}
}
