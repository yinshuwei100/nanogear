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
#include <Nanogear/Server>
#include <Nanogear/Concrete/HTTP/HTTPServer>
#include <Nanogear/Router>
#include <Nanogear/Resource/Resource>
#include <Nanogear/Resource/Representation>
#include <Nanogear/Resource/Directory>
#include <Nanogear/Status>

using namespace Nanogear;
using namespace Nanogear::Concrete::HTTP;
using namespace Nanogear::Resource;

int main(int argc, char** argv) {
    Application app(argc, argv);

    Directory* directory = new Directory(".");

    app.setServer(new HTTPServer());
    app.setRoot(directory);

    return app.exec();
}

