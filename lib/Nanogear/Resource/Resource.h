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

class Resource : public QObject {
    Q_OBJECT
public:
    Resource() {}

    Resource(const Context& context, QObject* parent = 0) : QObject(parent),
        m_context(context) { setObjectName(context.path()); }

    virtual ~Resource() {}

    virtual Response handleRequest(const Request&);

    virtual void setContext(const Context& context)
        { m_context = context; setObjectName(context.path()); }
    const Context& context() const
        { return m_context; }

protected:
    virtual Response handleGet(const Request& r) const { return methodNotSupported(r); }
    virtual Response handlePut(const Request& r) { return methodNotSupported(r); }
    virtual Response handlePost(const Request& r) { return methodNotSupported(r); }
    virtual Response handleOptions(const Request& r) const { return methodNotSupported(r); }
    virtual Response handleDelete(const Request& r) { return methodNotSupported(r); }
    virtual Response methodNotSupported(const Request& r) const { return Application::instance()->methodNotSupported(r); }
    virtual Response notFound(const Request& r) const { return Application::instance()->notFound(r); }

private:
    bool m_modifiable;
    Context m_context;
};

}
}

#endif // NANOGEAR_RESOURCE_RESOURCE_H
