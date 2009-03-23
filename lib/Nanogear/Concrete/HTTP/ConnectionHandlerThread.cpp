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

#include "../../Response.h"
#include "../../Request.h"
#include "../../Resource/Resource.h"
#include "../../Resource/Representation.h"

namespace Nanogear {
namespace Concrete {
namespace HTTP {

void ConnectionHandlerThread::run() {
    m_clientSocket = m_server->tcpServer()->nextPendingConnection();
    connect(m_clientSocket, SIGNAL(readyRead()), SLOT(onClientReadyRead()));
    connect(this, SIGNAL(finished()), SLOT(deleteLater()));
    connect(this, SIGNAL(finished()), m_clientSocket, SLOT(deleteLater()));
}

void ConnectionHandlerThread::onClientReadyRead() {
    if (m_clientSocket != 0) {
        qDebug() << Q_FUNC_INFO << "------ handling request (size:" << m_clientSocket->size() << ")";
        QByteArray inputBlock(m_clientSocket->readAll());

        QHttpRequestHeader requestHeader(inputBlock);
        Context requestPath = requestHeader.path();
        ClientInfo clientInfo(requestHeader.value("user-agent"));

        /* add mime types */ {
            QList< Preference<MimeType> > accept;
            foreach (const QString& mimeType, requestHeader.value("accept").remove(" ").split(",")) {
                QList<QString> pair = mimeType.split(";q=");
                accept.append(Preference<MimeType>(pair.at(0), pair.value(1, "1").toFloat()));
            }
            clientInfo.setAcceptedMimeTypes(accept);
        }
        /* add locales */ {
            QList< Preference<QLocale> > accept;
            foreach (const QString& locale, requestHeader.value("accept-language").remove(" ").split(",")) {
                QList<QString> pair = locale.split(";q=");
                accept.append(Preference<QLocale>(pair.at(0), pair.value(1, "1").toFloat()));
            }
            clientInfo.setAcceptedLocales(accept);
        }
        /* add text codecs */ {
            QList< Preference<QTextCodec*> > accept;
            foreach (const QString& codec, requestHeader.value("accept-charset").remove(" ").split(",")) {
                QList<QString> pair = codec.split(";q=");
                accept.append(Preference<QTextCodec*>(QTextCodec::codecForName(pair.at(0).toUtf8()), pair.value(1, "1").toFloat()));
            }
            clientInfo.setAcceptedTextCodecs(accept);
        }
        qDebug() << Q_FUNC_INFO << "requested path == " << requestHeader.path();
        qDebug() << Q_FUNC_INFO << "requested context == " << requestPath.path();

        Resource::Resource* resource = m_server->findChild<Resource::Resource*>(requestPath.path());
        Request request(requestHeader.method(), requestPath, clientInfo);
        Response response = resource ? resource->handleRequest(request) : Application::instance()->notFound(request);
        const Resource::Representation* representation = response.representation();
        QTextCodec* codec = Preference<QTextCodec*>::top(clientInfo.acceptedTextCodecs());

        QHttpResponseHeader responseHeader(response.status().code(), response.status().name(),
            requestHeader.majorVersion(), requestHeader.minorVersion());
        responseHeader.setValue("server", "Nanogear");
        responseHeader.setContentType(representation->format(clientInfo.acceptedMimeTypes()).toString());

        qDebug() << Q_FUNC_INFO << "sending data back to the client";
        m_clientSocket->write(responseHeader.toString().toUtf8());
        m_clientSocket->write(representation->data(clientInfo.acceptedMimeTypes()));

        qDebug() << Q_FUNC_INFO << "disconnecting from host";
        m_clientSocket->disconnectFromHost();
        m_clientSocket->waitForDisconnected();
    } else {
        qDebug() << Q_FUNC_INFO << "Socket error" << m_clientSocket->errorString();
    }
}

}
}
}
