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

#include <QHash>

#ifndef SERVER_H
#define SERVER_H

class QString;
class Application;

class Server : public QObject {
public:
    Server() {}
    Server(int port) : m_listenPort(port) {}
    virtual ~Server() {}
    
    void attach(const QString& context, Application*);
    virtual void start() = 0;

    void setListenPort(int port);
    int listenPort() const;

    const QHash<QString, Application*>& attachedApps() const;
private:
    int m_listenPort;
    QHash<QString, Application*> m_attachedApps;
};

#endif // SERVER_H
