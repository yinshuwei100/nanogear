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

#include "Application.h"

#include "Server.h"
#include "Response.h"
#include "Request.h"
#include "Status.h"

namespace Nanogear {


Application::Application(int argc, char** argv)
    : QCoreApplication(argc, argv) {}


void Application::setServer(Server* s) {
    m_server = s;
}
Server* Application::server() const {
    return m_server;
}


void Application::setRoot(Resource::Resource* root) {
    m_root = root;
}
Resource::Resource* Application::root() const {
    return m_root;
}


Application* Application::instance() {
    return static_cast<Application*>(QCoreApplication::instance());
}


Response Application::methodNotSupported(const Request& request) const {
    Q_UNUSED(request);
    return Response(Status::MethodNotAllowed, &m_methodNotSupported);
}


Response Application::notFound(const Request& request) const {
    Q_UNUSED(request);
    return Response(Status::NotFound, &m_notFound);
}


int Application::exec() {
    m_server->start();
    return QCoreApplication::exec();
}


} // namespace Nanogear

