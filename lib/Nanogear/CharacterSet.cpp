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

#include "CharacterSet.h"
#include <QMetaEnum>

namespace Nanogear {

int CharacterSet::toCharacterSetType(const QString& key) {
    const QMetaObject& metaObject = staticMetaObject;
    QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("CharacterSetType"));
    return metaEnum.keyToValue(key.toUtf8());
}

QString CharacterSet::toString(int value) {
    const QMetaObject& metaObject = staticMetaObject;
    QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("CharacterSetType"));
    return metaEnum.valueToKey(value);
}

QByteArray CharacterSet::convert(const QString& string) const {
    Q_ASSERT(m_set != Invalid);
    Q_ASSERT(m_set != Utf16); // QByteArray can't hold Utf16
    switch (m_set) {
    case Default:
        return string.toLocal8Bit();
    case Iso88591:
        return string.toLatin1();
    case UsAscii:
        return string.toAscii();
    case Utf8:
        return string.toUtf8();
    }
    return QByteArray();
}

}


