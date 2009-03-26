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

#include "Request.h"
#include <QString>
#include <QByteArray>
#include "Context.h"
#include "ClientInfo.h"
#include "Method.h"

namespace Nanogear {

struct Request::Private {
    Private() {};
    Private(const Method& m, const Context& c, const ClientInfo& cI)
        : method(m), context(c), clientInfo(cI) {};
    Method method;
    Context context;
    ClientInfo clientInfo;
    QByteArray body;
};

Request::Request() : d(new Private) {
    qRegisterMetaType<Request>();
}
Request::Request(const Method& m, const Context& c, const ClientInfo& cI)
    : d(new Private(m, c, cI)) {
    qRegisterMetaType<Request>();
}
Request::~Request() {
    delete d;
}

const Method& Request::method() const {
    return d->method;
}
void Request::setMethod(const Method& method) {
    d->method = method;
}

const Context& Request::context() const {
    return d->context;
}
void Request::setContext(const Context& context) {
    d->context = context;
}

void Request::setClientInfo(const ClientInfo& clientInfo) {
    d->clientInfo = clientInfo;
}
const ClientInfo& Request::clientInfo() const {
    return d->clientInfo;
}

void Request::setBody(const QByteArray& body) {
    d->body = body;
}
const QByteArray& Request::body() const {
    return d->body;
}

}

