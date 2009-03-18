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

#ifndef NANOGEAR_ROUTER_H
#define NANOGEAR_ROUTER_H

#include <QList>

#include "Resource/Resource.h"

class QString;

namespace Nanogear {

class Router : public Resource::Resource {
public:
    Router(const Context& context) : Resource::Resource(context) {}
    virtual ~Router() {}

    void attach(const QString& uri, Resource::Resource* resource);

    virtual Response handleRequest(const Request&);
    
    const QList<Resource::Resource*> attachedResources() const
        { return m_resources; }

private:
    QList<Resource::Resource*> m_resources;
};

}

#endif /* NANOGEAR_ROUTER_H */
