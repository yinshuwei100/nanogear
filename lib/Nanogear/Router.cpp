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

#include "Router.h"

#include "Resource/Resource.h"

#include <QRegExp>

namespace Nanogear {

void Router::attach(const QString& uri, Resource::Resource* resource) {
    m_resources.append(resource);
    Context c(context().contextPath() + uri);
    resource->setContext(c);
    qDebug() << Q_FUNC_INFO << " attatched " << c.contextPath();
}

void Router::setContext(const Context& newContext) {
    QString oldPath = context().contextPath();
    QString newPath = newContext.contextPath();
    qDebug() << Q_FUNC_INFO << oldPath << " -> " << newPath;
    foreach(Resource::Resource* resource, attachedResources()) {
        QString path = resource->context().contextPath();
        path.replace(QRegExp("^" + oldPath), newPath);
        qDebug() << Q_FUNC_INFO << resource->context().contextPath() << " -> " << path;
        resource->setContext(path);
    }
    Resource::Resource::setContext(newContext);
}

Response Router::handleRequest(const Request& req) {
    Response res = notFound(req);
    foreach(Resource::Resource* resource, attachedResources()) {
        if (resource->context() != req.context()) continue;
        res = resource->handleRequest(req);
        if (req.clientInf().acceptedMediaTypes().contains(res.mediaType())) break;
    }
    return res;
}

}


