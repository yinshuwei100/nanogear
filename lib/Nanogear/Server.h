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

#ifndef NANOGEAR_SERVER_H
#define NANOGEAR_SERVER_H

#include <QList>
#include <QObject>

#include "Context.h"

namespace Nanogear {

namespace Resource {
class Resource;
}

class Server : public QObject {
    Q_OBJECT
public:
    Server(int port = 8080, QObject* parent = 0) : QObject(parent), m_listenPort(port) {}
    virtual ~Server() {}

    void setContext(const Context& context)
        { m_context = context; }
    const Context& context() const
        { return m_context; }

    void setListenPort(int port)
        { m_listenPort = port; }
    int listenPort() const
        { return m_listenPort; }

public Q_SLOTS:
    virtual void start() = 0;

private:
    int m_listenPort;
    Context m_context;
};

}

#endif /* NANOGEAR_SERVER_H */
