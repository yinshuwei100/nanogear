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

#ifndef NANOGEAR_METHOD_H
#define NANOGEAR_METHOD_H

#include <QString>
#include <QObject>
#include <QMetaType>

namespace Nanogear {

class Method {
    Q_GADGET
    Q_ENUMS(Type);
public:
    Method() : m_method(Invalid) { qRegisterMetaType<Method>(); };
    Method(const QString& name) : m_method(toType(name)) { qRegisterMetaType<Method>(); };
    Method(const char* name) : m_method(toType(name)) { qRegisterMetaType<Method>(); };
    Method(int method) : m_method(method) { qRegisterMetaType<Method>(); };
    void fromString(const QString& name)
        { m_method = toType(name); }
    QString toString() const
        { return toString(m_method); }
    void fromType(int method)
        { m_method = method; }
    int toType() const
        { return m_method; }

    bool operator==(const Method& type) const
        { return m_method == type.m_method; }
    bool isValid() const
        { return m_method != Invalid; }

    enum Type {
        Invalid = 0,
        CONNECT = 1,
        COPY = 2,
        DELETE = 3,
        GET = 4,
        HEAD = 5,
        LOCK = 6,
        MKCOL = 7,
        MOVE = 8,
        OPTIONS = 9,
        POST = 10,
        PROPFIND = 11,
        PROPPATCH = 12,
        PUT = 13,
        TRACE = 14,
        UNLOCK = 15
    };
private:
    static int toType(const QString&);
    static QString toString(int method);
    int m_method;
};

}

Q_DECLARE_METATYPE(Nanogear::Method);

#endif // NANOGEAR_METHOD_H
