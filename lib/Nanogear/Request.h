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

#ifndef NANOGEAR_REQUEST_H
#define NANOGEAR_REQUEST_H

#include <QString>
#include <QMetaObject>
#include <QByteArray>

#include "ClientInfo.h"
#include "Method.h"

#include "Resource/Representation.h"

namespace Nanogear {

class Method;
class Context;
class ClientInfo;

/*!
 * \class Request
 * \brief This class encapsulates and abstracts a client request
 *
 * A Request object represents a client request. That is, every client, either
 * a web browser or another program, will usually include supported media types,
 * supported charset, the resource context, request method and request
 * parameters.
 *
 * It is connector's (or, in general, a Server implementation) responsiblity
 * to fill this object and pass a const reference to resources methods handlers.
 *
 * Informations sent by the client (such as supported media types, character
 * encodings, etc) is encapsulated in a ClientInfo object and is read-only.
 *
 * The requested context is encapsulated by a Context object and is read-only.
 *
 * The request body is represented by a read-only QByteArray
 */
class Request {
public:
    /*!
     * Default constructor. Invalid method, empty context, empty clientInfo.
     */
    Request();

    /*!
     * A constructor used to initialize values.
     * This constructor is intended to be used only by 'Server' implementations
     *
     * \param method A const reference to a Method object
     * \param clientInfo A const reference to a ClientInfo
     * \param body A pointer to the body representation
     */
    Request(const Method& method, const ClientInfo& clientInfo, Resource::Representation* body) :
        m_method(method), m_clientInfo(clientInfo), m_representation(body) {}

        
    /*!
     * When a client makes a request it usually specifies a method. It used to
     * determine which handler should be called on a resource.
     * \return An object encapsulating a method
     */
    const Method& method() const
        { return m_method; }

    void setMethod(const Method& method)
        { m_method = method; }

    /*!
     * A client usually attaches additional informations to the request, this
     * method can be used to retrieve it.
     * \return An object representing additional informations supplied by the client
     */
    const ClientInfo& clientInfo() const
        { return m_clientInfo; }

    void setClientInfo(const ClientInfo& clientInfo)
        { m_clientInfo = clientInfo; }

    /*!
     * Set the representation attached to this Request
     * \param representation A pointer to a Representation object
     */
    void setRepresentation(Resource::Representation* representation)
        { m_representation = representation; }

    /*!
     * \return The representation attached to this request
     */
    const Resource::Representation* representation() const
        { return m_representation; }

    /*!
     * Set the path requested by the client
     * \param path A string representing the requested path
     */
    void setPath(const QString& path)
        { m_path = path; }

    /*!
     * \return The path requested by the client
     */
    const QString& path() const
        { return m_path; }

private:
    Method m_method;
    ClientInfo m_clientInfo;
    QString m_path;
    Resource::Representation* m_representation;
};

}

Q_DECLARE_METATYPE(Nanogear::Request)

#endif /* NANOGEAR_REQUEST_H */
