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

#include <Nanogear/Application>
#include <Nanogear/Router>
#include <Nanogear/Server>
#include <Nanogear/Resource/Representation>
#include <Nanogear/Resource/StringRepresentation>
#include <Nanogear/Resource/Resource>
#include <Nanogear/Concrete/HTTP/HTTPServer>

using namespace Nanogear;
using namespace Nanogear::Concrete::HTTP;

class RootResource : public Resource::Resource {
public:
    RootResource() : srep("<h1>Test response</h1>", "text/html") {}
    virtual Response handleGet(const Request&) {
        qDebug() << Q_FUNC_INFO << "called";
        return Response(200, &srep);
    }

private:
    Nanogear::Resource::StringRepresentation srep;
};

class SimpleApplication : public Application {
public:
    SimpleApplication() : srep("<h1>Simple Application</h1><a href=\"resource\">Resource</a>", "text/html") {
        attach("/resource", &m_rootResource);
    }
    virtual Response handleGet(const Request&) {
        qDebug() << Q_FUNC_INFO << "called";
        return Response(200, &srep);
    }
private:
    Nanogear::Resource::StringRepresentation srep;
    RootResource m_rootResource;
};

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    SimpleApplication simpleApp;

    HTTPServer server(8080);
    server.attach("/", &simpleApp);
    server.start();
    
    return app.exec();
}

