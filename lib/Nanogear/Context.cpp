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

#include "Context.h"
#include <QRegExp>
#include <QString>

namespace Nanogear {

struct Context::Private {
    Private() {};
    Private(const QString& p) : path(sanitize(p)) {};
    static QString sanitize(QString);
    QString path;
};

Context::Context() : d(new Private()) {}
Context::Context(const QString& path) : d(new Private(path)) {
    qRegisterMetaType<Context>();
}
Context::Context(const char* charPath) : d(new Private(charPath)) {
    qRegisterMetaType<Context>();
}
Context::~Context() {
    delete d;
}

void Context::setPath(const QString& path)
    { d->path = d->sanitize(path); }
const QString& Context::path() const
    { return d->path; }

QString Context::Private::sanitize(QString path) {
    return path.replace("//", "/").remove(QRegExp("/$"));
}

bool operator==(const Context& a, const Context& b) {
    return a.path() == b.path();
}

bool operator!=(const Context& a, const Context& b) {
    return a.path() != b.path();
}

}

