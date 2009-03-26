/*
 * Nanogear - C++ web development framework
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

#include <QCoreApplication>
#include <QDebug>

#include <Nanogear/Application>
#include <Nanogear/Server>
#include <Nanogear/Resource/Representation>
#include <Nanogear/Resource/Resource>
#include <Nanogear/Concrete/HTTP/HTTPServer>
#include <Nanogear/Status>

using namespace Nanogear;
using namespace Nanogear::Concrete::HTTP;

class RootResource : public Resource::Resource {
public:
    RootResource(const Context& c, QObject* parent)
        : Resource(c, parent), m_representation("<h1>Test response</h1>", "text/html") {}

    virtual Response handleGet(const Request&) const {
        qDebug() << Q_FUNC_INFO << "called";
        return Response(Status::OK, &m_representation);
    }

private:
    Nanogear::Resource::Representation m_representation;
};

class Root : public Resource::Resource {
public:
    Root(const Context& c, QObject* par)
        : Resource(c, par),
          m_representation("<h1>Simple Application</h1><a href=\"resource\">Resource</a>", "text/html"),
          m_rootResource("/resource", this) {}

    virtual Response handleGet(const Request&) const {
        qDebug() << Q_FUNC_INFO << "called";
        return Response(Status::OK, &m_representation);
    }
private:
    Nanogear::Resource::Representation m_representation;
    RootResource m_rootResource;
};

int main(int argc, char** argv) {
    Application app(argc, argv);
    app.setServer(new HTTPServer(8080, &app));
    app.setRoot(new Root("/", app.server()));

    return app.exec();
}

