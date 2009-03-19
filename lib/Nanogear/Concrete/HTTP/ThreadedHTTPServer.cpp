/*
 * Nanogear - C++ web development framework
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

#include "ThreadedHTTPServer.h"
#include "ConnectionHandlerThread.h"

namespace Nanogear {
namespace Concrete {
namespace HTTP {

void ThreadedHTTPServer::incomingConnection(int socketDescriptor) {
    qDebug() << Q_FUNC_INFO << "received new connection (descriptor" << socketDescriptor << ")";

    ConnectionHandlerThread* handlerThread =
        new ConnectionHandlerThread(parent(), socketDescriptor);
    connect(handlerThread, SIGNAL(finished()), handlerThread, SLOT(deleteLater()));

    qDebug() << Q_FUNC_INFO << "handling request in a new thread";
    handlerThread->start();
}

}
}
}
