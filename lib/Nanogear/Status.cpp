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

#include "Status.h"
#include <QMetaEnum>
#include <QString>

namespace Nanogear {

struct Status::Private {
    Private() : status(Invalid) {};
    Private(const QString& name) : status(toType(name)) {};
    Private(int s) : status(s) {};
    static int toType(const QString&);
    static QString toString(int status);
    int status;
};

Status::Status() : d(new Private()) {
    qRegisterMetaType<Status>();
}
Status::Status(const QString& name) : d(new Private(name)) {
    qRegisterMetaType<Status>();
}
Status::Status(const char* name) : d(new Private(name)) {
    qRegisterMetaType<Status>();
}
Status::Status(int status) : d(new Private(status)) {
    qRegisterMetaType<Status>();
}
Status::~Status() {
    delete d;
}

void Status::fromString(const QString& name)
    { d->status = d->toType(name); }
QString Status::toString() const
    { return d->toString(d->status); }

void Status::fromType(int status)
    { d->status = status; }
int Status::toType() const
    { return d->status; }

bool Status::operator==(const Status& type) const
    { return d->status == type.d->status; }
bool Status::isValid() const
    { return d->status != Invalid; }

int Status::Private::toType(const QString& key) {
    const QMetaObject& metaObject = staticMetaObject;
    QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Type"));
    return metaEnum.keyToValue(key.toUtf8());
}

QString Status::Private::toString(int value) {
    const QMetaObject& metaObject = staticMetaObject;
    QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Type"));
    return metaEnum.valueToKey(value);
}

}

