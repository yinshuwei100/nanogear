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

#include <QString>
#include <QDebug>
#include "MimeType.h"

namespace Nanogear {

struct MimeType::Private {
    Private() : whole("*/*"), category("*"), specific("*") {}
    Private(const QString& type) : whole(type), category("*"), specific("*") {}
    QString whole;
    QString category;
    QString specific;
};

MimeType::MimeType() : d(new Private()) {
    qRegisterMetaType<MimeType>();
}
MimeType::MimeType(const QString& type) : d(new Private(type)) {
    qRegisterMetaType<MimeType>();
}
MimeType::MimeType(const char* type) : d(new Private(type)) {
    qRegisterMetaType<MimeType>();
}
MimeType::~MimeType() {
    delete d;
}

void MimeType::fromString(const QString& type) {
    d->whole = type;
    d->category.clear();
    d->specific.clear();
}
const QString& MimeType::toString() const {
    return d->whole;
}

bool MimeType::operator==(const MimeType& type) const {
    return d->whole == type.d->whole;
}
bool MimeType::isConcrete() const {
    return !d->whole.contains("*");
}

const QString& MimeType::category() const {
    if (d->category.isEmpty())
        const_cast<MimeType*>(this)->d->category = d->whole.left(d->whole.indexOf('/'));
    return d->category;
}

const QString& MimeType::specific() const {
    if (d->category.isEmpty())
        const_cast<MimeType*>(this)->d->specific = d->whole.right(d->whole.indexOf('/'));
    return d->specific;
}

bool MimeType::isCompatible(const MimeType& other) const {
    return other.d->whole.contains(d->whole) ||\
           d->whole.contains(other.d->whole);
}

}

