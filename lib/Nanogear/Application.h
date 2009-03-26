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


#ifndef NANOGEAR_APPLICATION_H
#define NANOGEAR_APPLICATION_H

#include <QCoreApplication>
#include "Response.h"
#include "Resource/Representation.h"
#include "Request.h"

namespace Nanogear {

class Server;

namespace Resource {
class Resource;
}

/*!
 * \class Application
 * \brief A Nanogear application
 *
 * This class represents a Nanogear and inherits from QCoreApplication.
 * It is responsible for starting the event loop and the attached connector.
 */
class Application : public QCoreApplication {
public:
    /*!
     * Initialize this Nanogear application
     *
     * The argc and argv arguments are processed by the application, and made
     * available in a more convenient form by the arguments() function.
     *
     * Warning: The data pointed to by argc and argv must stay valid for the
     * entire lifetime of the QCoreApplication object.
     */
    Application(int argc, char** argv) : QCoreApplication(argc, argv),
        m_methodNotSupported("<h1>Method not supported</h1>", "text/html"),
        m_notFound("<h1>Not Found</h1>", "text/html") {};

    /*!
     * Attach a server to this application. The server is automatically started
     * when calling exec()
     * \param server a pointer to a concrete implementation of the server class
     */
    void setServer(Server* server)
        { m_server = server; }

    /*!
     * \return The currently attached server
     */
    Server* server() const
        { return m_server; }

    /*!
     * Sets the root resource. Such resource will typically respond to request
     * made on the root context ("/") relative to the application's context
     * \param resource a pointer a Nanogear::Resource::Resource
     */
    void setRoot(Resource::Resource* resource)
        { m_root = resource; }

    /*!
     * \return The root resource
     */
    Resource::Resource* root() const
        { return m_root; }

    /*!
     * Retrieve an instance of this Nanogear application
     * \return A pointer to the current instance
     */
    static Application* instance()
        { return static_cast<Application*>(QCoreApplication::instance()); }

    /*!
     * \return a default Response when a method is not supported
     */
    virtual Response methodNotSupported(const Request& r) const
        { return Response(Status::MethodNotAllowed, &m_methodNotSupported); }

    /*!
     * \return a default Response when a resource is not found
     */
    virtual Response notFound(const Request& r) const
        { return Response(Status::NotFound, &m_notFound); }

    /*!
     * Start this Nanogear application. This method will also call the
     * Server::start() method for you.
     * \return The value set to exit() (which is 0 if you call quit())
     */
    int exec();

private:
    Server* m_server;
    Resource::Resource* m_root;
    Resource::Representation m_methodNotSupported;
    Resource::Representation m_notFound;
};

}

#endif /* NANOGEAR_APPLICATION_H */
