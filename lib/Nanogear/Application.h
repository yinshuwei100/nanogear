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
#include "Server.h"
#include "Resource/StringRepresentation.h"
#include "Response.h"
#include "Request.h"

namespace Nanogear {

namespace Resource {
class Resource;
}

class Application : public QCoreApplication {
    Q_OBJECT
public:
    Application(int argc, char** argv) : QCoreApplication(argc, argv),
        m_methodNotSupported("<h1>Method not supported</h1>", "text/html"),
        m_notFound("<h1>Not Found</h1>", "text/html") {};

    virtual ~Application() {};

    void setServer(Server* s)
        { m_server = s; }
    Server* server() const
        { return m_server; }

    void setRoot(Resource::Resource* r)
        { m_root = r; }
    Resource::Resource* root() const
        { return m_root; }

    int exec()
        { m_server->start(); return QCoreApplication::exec(); }
    static Application* instance()
        { return static_cast<Application*>(QCoreApplication::instance()); }

    virtual Response methodNotSupported(const Request& r) { qDebug() << Q_FUNC_INFO; return Response(501, &m_methodNotSupported); }
    virtual Response notFound(const Request& r) { qDebug() << Q_FUNC_INFO; return Response(404, &m_notFound); }

private:
    Server* m_server;
    Resource::Resource* m_root;
    Resource::StringRepresentation m_methodNotSupported;
    Resource::StringRepresentation m_notFound;
};

}

#endif /* NANOGEAR_APPLICATION_H */
