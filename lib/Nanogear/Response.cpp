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

#include "Response.h"
#include "Status.h"
#include <QDateTime>

namespace Nanogear {

struct Response::Private {
    Private() : status(Status::OK), representation(0),
        expires(QDateTime::currentDateTime()) {}
    Private(const Status& s, const Resource::Representation* rep) : status(s),
        representation(rep), expires(QDateTime::currentDateTime()) {}
    Private(const Status& s, const Resource::Representation* rep, const QDateTime& exp) : status(s),
        representation(rep), expires(exp) {}
    Status status;
    const Resource::Representation* representation;
    QDateTime expires;
};

Response::Response() : d(new Private()) {
    qRegisterMetaType<Response>();
}
Response::Response(const Status& s, const Resource::Representation* rep) : d(new Private(s, rep)) {
    qRegisterMetaType<Response>();
}
Response::Response(const Status& s, const Resource::Representation* rep, const QDateTime& expires)
    : d(new Private(s, rep, expires)) {
    qRegisterMetaType<Response>();
}
Response::~Response() {
    delete d;
}

void Response::setStatus(const Status& s) {
    d->status = s;
}
const Status& Response::status() {
    return d->status;
}

void Response::setRepresentation(const Resource::Representation* representation) {
    d->representation = representation;
}
const Resource::Representation* Response::representation() const {
    return d->representation;
}

void Response::setExpires(const QDateTime& expires) {
    d->expires = expires;
}
const QDateTime& Response::expires() const {
    return d->expires;
}

}

