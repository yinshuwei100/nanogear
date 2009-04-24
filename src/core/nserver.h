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

#ifndef NSERVER_H
#define NSERVER_H

#include <QHostAddress>

/*!
 * \class NServer
 * \brief Abstract class representing a generic Server
 *
 * This abstract class is implemented by concrete server.
 *
 * A Server is usually attached to an Application object.
 */

class NServer
{
public:
    /*!
     * The default constructor
     * \param port The server will listen on to this port
     * \param parent The parent of this object
     */
    NServer(int port = 8080, const QHostAddress& listenAddress = QHostAddress::Any) :
            m_listenPort(port), m_listenAddress(listenAddress) {}

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

    /*!
     * Set the address onto the server listens for new connections
     * \param listenAddress An IPv4/IPv6 address encapsulated in a QHostAddress
     */
    void setListenAddress(const QHostAddress& listenAddress)
    { m_listenAddress = listenAddress; }

    /*!
     * \return The current listening address
     */
    const QHostAddress& listenAddress() const
    { return m_listenAddress; }

    /*!
     * This method is called by NApplication::exec and is used to start the
     * server connector.
     */
    virtual void start() = 0;

private:
    int m_listenPort;
    QHostAddress m_listenAddress;
};

#endif /* NSERVER_H */
