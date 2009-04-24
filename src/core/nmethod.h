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

#ifndef NMETHOD_H
#define NMETHOD_H

#include <QObject>
#include <QString>

/*!
 * \class NMethod
 * \brief Encapsulates the requested method
 *
 * Used to determine which method to execute to handle a request. It is usually
 * filled by a concrete implementation of Server.
 */

class NMethod
{
    Q_GADGET
    Q_ENUMS(Type)
public:
    /*!
     * Default constructor. Builds a invalid method.
     */
    NMethod() : m_method(Invalid) {}

    /*!
     * Build a Method object from its name
     * \param name method's name
     */
    NMethod(const QString& name) : m_method(toType(name)) {}

    /*!
     * This is an overloaded constructor provided for convenience
     * \param name method's name (C-style string)
     */
    NMethod(const char* name) : m_method(toType(name)) {}

    /*!
     * This is an overloaded constructor provided for convenience
     * \param method the code representing a method
     */
    NMethod(int method) : m_method(method) {}

    /*!
     * Build this object from the name of the method
     * \param name Method name
     */
    void fromString(const QString& name)
    { toType(name); }

    /*!
     * \return Return the method name as a string
     */
    QString toString() const
    { return toString(m_method); }

    /*!
     * Build this method from its integer code
     * \param method
     */
    void fromType(int method)
    { m_method = method; }

    /*!
     * \return the code associated with this method
     */
    int toType() const
    { return m_method; }

    bool operator==(const NMethod& type) const
    { return m_method == type.m_method; }

    /*!
     * \return If this method is valid or not
     */
    bool isValid() const
    { return m_method != Invalid; }

    /*!
     * \return true if this method has a body
     */
    bool hasBody() const;

    /*!
     * Various connection types, names are derived from HTTP 1.1 method
     * definition. This enum includes also WebDav request method types
     * \see http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html
     * \see http://www.webdav.org/specs/rfc2518.html#http.methods.for.distributed.authoring
     */
    enum Type {
        Invalid = -1,
        OPTIONS,   /* HTTP 1.1 standard methods */
        GET,
        HEAD,
        POST,
        PUT,
        DELETE,
        TRACE,
        CONNECT,
        PROPFIND,   /* WebDAV request methods */
        PROPPATCH,
        MKCOL,
        COPY,
        MOVE,
        LOCK,
        UNLOCK
    };

private:
    /*!
     * Get the status code name as string from its number
     * \param value The status code
     */
    QString toString(int value) const;
    
    /*!
     * Get the status code number from its name
     * \param key The status name
     */
    int toType(const QString& key) const;

private:
    int m_method;
};

#endif /* NMETHOD_H */
