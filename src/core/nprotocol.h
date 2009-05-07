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

#ifndef NPROTOCOL_H
#define	NPROTOCOL_H

#include <QObject>

class NProtocol
{
    Q_GADGET
    Q_ENUMS(Type)
public:

    /*!
     * Default constructor using the HTTP protocol.
     */
    NProtocol() : m_protocol(HTTP) {}

    /*!
     * Construct the status from its name
     * \param name The status name
     */
    NProtocol(const QString& name) : m_protocol(toType(name)) {}

    /*!
     * An overloaded constructor provided for convenience
     * \param name The status name as C-style string
     */
    NProtocol(const char* name) : m_protocol(toType(name)) {}

    /*!
     * Construct this Status from its code
     * \param status the status code
     */
    NProtocol(int status) : m_protocol(status) {}

    /*!
     * Construct the status from its name
     * \param name The status name
     */
    void fromString(const QString& name)
    { m_protocol = toType(name); }

    /*!
     * \return The string representation of this status code
     */
    QString toString() const
    { return toString(m_protocol); }

    /*!
     * Construct this Status from its code
     * \param status the status code
     */
    void fromType(int status)
    { m_protocol = status; }

    /*!
     * \return The status code
     */
    int toType() const
    { return m_protocol; }

    bool operator==(const NProtocol& type) const
    { return m_protocol == type.m_protocol; }

    /*!
     * This enum holds HTTP status codes
     * \see http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html
     */
    enum Protocol {
        HTTP = 0,
        HTTPS,
        FILE
    };

private:
    /*!
     * Get the protocol name from it's enum index
     * \param value The protocol code
     */
    QString toString(int value) const;

    /*!
     * Get the protocol's enum index from it's name
     * \param key The protocol name
     */
    int toType(const QString& key) const;

    int m_protocol;
};

#endif	/* NPROTOCOL_H */

