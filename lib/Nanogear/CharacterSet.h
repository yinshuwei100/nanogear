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

#ifndef NANOGEAR_CHARACTERSET_H
#define NANOGEAR_CHARACTERSET_H

#include <QString>
#include <QObject>

namespace Nanogear {

class CharacterSet {
    Q_GADGET
    Q_ENUMS(CharacterSetType);
public:
    CharacterSet() {};
    CharacterSet(const QString& name) : m_set(toCharacterSetType(name)) {};
    CharacterSet(const char* name) : m_set(toCharacterSetType(name)) {};
    void fromString(const QString& name)
        { m_set = toCharacterSetType(name); }
    QString toString() const
        { return toString(m_set); }
    void fromCharacterSetType(int set)
        { m_set = set; }
    int toCharacterSetType() const
        { return m_set; }

    bool operator==(const CharacterSet& set) const
        { return m_set == set.m_set; }
    bool isValid() const
        { return m_set != Invalid; }

    enum CharacterSetType {
        Invalid = 0,
        Default = 1,
        Iso88591 = 2,
        UsAscii = 3,
        Utf16 = 4,
        Utf8 = 5
    };
private:
    static int toCharacterSetType(const QString&);
    static QString toString(int set);
    int m_set;
};

}

#endif // NANOGEAR_CHARACTERSET_H
