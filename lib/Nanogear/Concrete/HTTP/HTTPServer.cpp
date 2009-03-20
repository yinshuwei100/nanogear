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
#include "ConnectionHandlerThread.h"

#include <QTcpSocket>

namespace Nanogear {
namespace Concrete {
namespace HTTP {

void HTTPServer::onNewConnection() {
    qDebug() << Q_FUNC_INFO << "received new connection";

    QTcpSocket* client = m_tcpServer.nextPendingConnection();
    connect(client, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
}

void HTTPServer::onClientReadyRead() {
    qDebug() << Q_FUNC_INFO << "the client is ready to send data, starting a new thread...";

    QTcpSocket* client = static_cast<QTcpSocket*>(sender());

    ConnectionHandlerThread* handlerThread =
        new ConnectionHandlerThread(client, this);
    connect(handlerThread, SIGNAL(finished()), handlerThread, SLOT(deleteLater()));
    connect(handlerThread, SIGNAL(finished()), client, SLOT(deleteLater()));

    qDebug() << Q_FUNC_INFO << "handling request in a new thread";
    handlerThread->start();
}


}
}
}
