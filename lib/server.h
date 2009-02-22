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

#ifndef SERVER_H
#define SERVER_H

#include <QList>

#include "context.h"

class QString;
class Application;

class Server {
public:
    Server(int port = 8080) : m_listenPort(port) {}
    virtual ~Server() {}
    
    void attach(const QString& context, Application*);
    virtual void start() = 0;

    const QList<Application*>& attachedApplications() const
        { return m_applications; }
    
    void setContext(const Context& context)
        { m_context = context; }
    const Context& context() const
        { return m_context; }

    void setListenPort(int port)
        { m_listenPort = port; }
    int listenPort() const
        { return m_listenPort; }
        
private:
    int m_listenPort;
    Context m_context;
    QList<Application*> m_applications;
};

#endif // SERVER_H
