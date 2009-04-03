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

#include <QObject>

#include "Context.h"

namespace Nanogear {

namespace Resource {
class Resource;
}

/*!
 * \class Server
 * \brief Abstract class representing a generic Server
 *
 * This abstract class is implemented by concrete server.
 *
 * A Server is usually attached to an Application object.
 *
 * Nanogear ships with a concrete, multi-threaded HTTP server.
 */
class Server : public QObject {
    Q_OBJECT
public:
    /*!
     * The default constructor
     * \param port The server will listen on to this port
     * \param parent The parent of this object
     */
    Server(int port = 8080, QObject* parent = 0) : QObject(parent), m_listenPort(port) {}

    virtual ~Server() {}

    /*!
     * Set the root context of this application
     * \param context Context
     */
    void setContext(const Context& context)
        { m_context = context; }

    /*!
     * \return The context of this application
     */
    const Context& context() const
        { return m_context; }

    /*!
     * Set the listen port for this server
     * \param port Listen port
     */
    void setListenPort(int port)
        { m_listenPort = port; }

    /*!
     * \return The listen port
     */
    int listenPort() const
        { return m_listenPort; }

public slots:
    /*!
     * Concrete implementation of Server must implement this function
     */
    virtual void start() = 0;

private:
    int m_listenPort;
    Context m_context;
};

}

#endif /* NANOGEAR_SERVER_H */
