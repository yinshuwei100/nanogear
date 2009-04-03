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

#ifndef NANOGEAR_RESOURCE_RESOURCE_H
#define NANOGEAR_RESOURCE_RESOURCE_H

#include <QObject>

#include "../Context.h"
#include "../Response.h"
#include "../Application.h"

namespace Nanogear {

class Request;

namespace Resource {

class Representation;

/*!
 * \class Resource
 * \brief The conceptual target of an hypertext reference
 *
 * "The key abstraction of information in REST is a resource. Any information
 * that can be named can be a resource: a document or image, a temporal service
 * (e.g. "today's weather in Los Angeles"), a collection of other resources,
 * a non-virtual object (e.g. a person), and so on. In other words, any concept
 * that might be the target of an author's hypertext reference must fit within
 * the definition of a resource. A resource is a conceptual mapping to a set of
 * entities, not the entity that corresponds to the mapping at any particular
 * point in time."
 *
 * \see Roy Fielding's dissertation at:
 *     http://roy.gbiv.com/pubs/dissertation/rest_arch_style.htm#sec_5_2_1_1
 */
class Resource : public QObject {
    Q_OBJECT
public:
    /*!
     * A constructor taking a Context and a parent object
     * \param context this resource context
     * \param parent parent to this resource
     */
    Resource(const Context& context, QObject* parent = 0) : QObject(parent),
        m_context(context) { setObjectName(context.path()); }

    virtual ~Resource() {}


    /*!
     * This method is used internally to dispatch the request to the
     * appropriate handler
     * \param request a reference to a Request object
     * \return a response object
     */
    virtual Response handleRequest(const Request&);

    /*!
     * Set the context associated with this resource
     * \param context the context associated with this resource
     */
    virtual void setContext(const Context& context)
        { m_context = context; setObjectName(context.path()); }

    /*!
     * \returns the context associated with this resource
     */
    const Context& context() const
        { return m_context; }

protected:
    /*!
     * Override this method in a derived class to handle a GET request.
     * By default this methods returns Status::MethodNotAllowed
     * \param request const reference to a Request object
     * \return the resource is responsible for compiling a Response object which
     *    will be sent to the client
     */
    virtual Response handleGet(const Request& request) const
        { return methodNotSupported(request); }

    /*!
     * Override this method in a derived class to handle a HEAD request.
     * By default this methods returns Status::MethodNotAllowed
     * \note this method is much like GET but must NOT return a response body
     *    (a Representation)
     * \param request const reference to a Request object
     * \return the resource is responsible for compiling a Response object which
     *    will be sent to the client
     */
    virtual Response handleHead(const Request& request)
        { return methodNotSupported(request); }

    /*!
     * Override this method in a derived class to handle a PUT request.
     * By default this methods returns Status::MethodNotAllowed
     * \param request const reference to a Request object
     * \return the resource is responsible for compiling a Response object which
     *    will be sent to the client
     */
    virtual Response handlePut(const Request& request)
        { return methodNotSupported(request); }

    /*!
     * Override this method in a derived class to handle a POST request.
     * By default this methods returns Status::MethodNotAllowed
     * \param request const reference to a Request object
     * \return the resource is responsible for compiling a Response object which
     *    will be sent to the client
     */
    virtual Response handlePost(const Request& request)
        { return methodNotSupported(request); }
        
    /*!
     * Override this method in a derived class to handle a OPTIONS request.
     * By default this methods returns Status::MethodNotAllowed
     * \param request const reference to a Request object
     * \return the resource is responsible for compiling a Response object which
     *    will be sent to the client
     */
    virtual Response handleOptions(const Request& request) const
        { return methodNotSupported(request); }

    /*!
     * Override this method in a derived class to handle a DELETE request.
     * By default this methods returns Status::MethodNotAllowed
     * \param request const reference to a Request object
     * \return the resource is responsible for compiling a Response object which
     *    will be sent to the client
     */
    virtual Response handleDelete(const Request& request)
        { return methodNotSupported(request); }

    /*!
     * Respond with Status::MethodNotAllowed
     * \param request const reference to a Request object
     * \return a default Response saying that the requested method is not allowed
     */
    virtual Response methodNotSupported(const Request& request) const
        { return Application::instance()->methodNotSupported(request); }

    /*!
     * Respond with Status::MethodNotAllowed
     * \param request const reference to a Request object
     * \return a default Response saying that the requested resource was not found
     */
    virtual Response notFound(const Request& request) const
        { return Application::instance()->notFound(request); }

private:
    bool m_modifiable;
    Context m_context;
};

}
}

#endif // NANOGEAR_RESOURCE_RESOURCE_H
