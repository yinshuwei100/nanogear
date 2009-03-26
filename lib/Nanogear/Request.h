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

#ifndef NANOGEAR_REQUEST_H
#define NANOGEAR_REQUEST_H

#include <QMetaType>

class QString;

namespace Nanogear {

class Method;
class Context;
class ClientInfo;

class Request {
public:
    Request();
    Request(const Method& m, const Context& c, const ClientInfo& cI);
    virtual ~Request();

    const Method& method() const;
    void setMethod(const Method& method);

    const Context& context() const;
    void setContext(const Context& context);

    void setClientInfo(const ClientInfo& clientInfo);
    const ClientInfo& clientInfo() const;

    void setBody(const QByteArray& body);
    const QByteArray& body() const;

private:
    struct Private;
    Private* d;
};

}

Q_DECLARE_METATYPE(Nanogear::Request);

#endif /* NANOGEAR_REQUEST_H */
