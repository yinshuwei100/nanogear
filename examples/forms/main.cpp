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

#include <QString>
#include <QDebug>

#include <Nanogear/Application>
#include <Nanogear/Concrete/HTTP/HTTPServer>
#include <Nanogear/Status>
#include <Nanogear/Response>
#include <Nanogear/Request>
#include <Nanogear/Resource/Resource>
#include <Nanogear/Resource/Representation>

using namespace Nanogear;
using namespace Nanogear::Concrete::HTTP;
using namespace Nanogear::Resource;

class FormsExample : public Nanogear::Resource::Resource {
public:
    virtual void handleGet(const Request& request, Response& response) {
        QString parametersString;
        foreach (const QString& key, request.parameters().keys()) {
            parametersString += (key + " = " + request.parameters()[key] + "\n");
        }
    
        m_representation.setHtml(QString("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" \"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">\n"
"<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"en\">\n"
"<head>\n"
"<title>Forms example</title>\n"
"</head>\n"
"<body>\n"
"<h2>Forms example</h2>\n"
"<h3>Get</h3>\n"
"<form name=\"input\" action=\"get.do\" method=\"get\">\n"
"<input type=\"text\" name=\"example\" />\n"
"<input type=\"submit\" value=\"Submit\" />\n"
"</form>\n"
"<h3>Post</h3>\n"
"<form name=\"input\" action=\"post.do\" method=\"post\">\n"
"<input type=\"text\" name=\"example\" />\n"
"<input type=\"submit\" value=\"Submit\" />\n"
"</form>\n"
"<hr/>\n"
"%1\n"
"</body>\n"
"</html>\n").arg(parametersString));

        response.setStatus(Status::OK);
        response.setRepresentation(&m_representation);
    }

    virtual void handlePost(const Request& request, Response& response) {
        handleGet(request, response);
    }
private:
    Representation m_representation;
};

int main(int argc, char** argv) {
    Application app(argc, argv);

    FormsExample example;

    app.setServer(new HTTPServer());
    app.setRoot(&example);

    return app.exec();
}

