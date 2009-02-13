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

#ifndef QHTTPSERVER_H
#define QHTTPSERVER_H

#include <QHash>
#include <QTcpServer>

class QString;
class QHostAddress;
class Resource;

class QHttpServer : public QTcpServer
{
    Q_OBJECT
public:
    QHttpServer(const QHostAddress& addr = QHostAddress::Any, int port = 8080);
    virtual ~QHttpServer() {};
    void attachResource(const QString& path, Resource*);
private slots:
    void onNewConnection();
    void onClientReadyRead();
private:
    QHash<QString, Resource*> m_resources;
};

#endif // QHTTPSERVER_H
