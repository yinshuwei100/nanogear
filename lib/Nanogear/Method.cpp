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

#include "Method.h"
#include <QMetaEnum>
#include <QString>

namespace Nanogear {

struct Method::Private {
    Private() : method(Invalid) {};
    Private(const QString& name) : method(toType(name)) {};
    Private(int m) : method(m) {};
    static int toType(const QString&);
    static QString toString(int method);
    int method;
};

Method::Method() : d(new Private()) {
    qRegisterMetaType<Method>();
}
Method::Method(const QString& name) : d(new Private(name)) {
    qRegisterMetaType<Method>();
}
Method::Method(const char* name) : d(new Private(name)) {
    qRegisterMetaType<Method>();
}
Method::Method(int method) : d(new Private(method)) {
    qRegisterMetaType<Method>();
}
Method::~Method() {
    delete d;
}

void Method::fromString(const QString& name) {
    d->method = d->toType(name);
}
QString Method::toString() const {
    return d->toString(d->method);
}

void Method::fromType(int method) {
    d->method = method;
}
int Method::toType() const {
    return d->method;
}

bool Method::operator==(const Method& type) const {
    return d->method == type.d->method;
}
bool Method::isValid() const {
    return d->method != Invalid;
}

bool Method::hasBody() const {
    switch (d->method) {
        // More?
        case POST:
        case PUT:
            return true;
    }
    return false;
}

int Method::Private::toType(const QString& key) {
    const QMetaObject& metaObject = staticMetaObject;
    QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Type"));
    return metaEnum.keyToValue(key.toUtf8());
}

QString Method::Private::toString(int value) {
    const QMetaObject& metaObject = staticMetaObject;
    QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Type"));
    return metaEnum.valueToKey(value);
}

}

