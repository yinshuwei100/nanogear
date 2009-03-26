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

namespace Nanogear {

class Server;
class Request;

namespace Resource {
class Resource;
}

class Application : public QCoreApplication {
    Q_OBJECT
public:
    Application(int argc, char** argv);

    virtual ~Application();

    void setServer(Server* s);
    Server* server() const;

    void setRoot(Resource::Resource* r);
    Resource::Resource* root() const;

    static Application* instance();

    virtual Response methodNotSupported(const Request& r) const;
    virtual Response notFound(const Request& r) const;

    int exec();

private:
    struct Private;
    Private* d;
};

}

#endif /* NANOGEAR_APPLICATION_H */
