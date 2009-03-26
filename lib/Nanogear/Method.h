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

#include <QObject>
#include <QMetaType>

class QString;

namespace Nanogear {

class Method {
    Q_GADGET
    Q_ENUMS(Type);
public:
    Method();
    Method(const QString& name);
    Method(const char* name);
    Method(int method);
    ~Method();

    void fromString(const QString& name);
    QString toString() const;

    void fromType(int method);
    int toType() const;

    bool operator==(const Method& type) const;
    bool isValid() const;
    bool hasBody() const;

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
    struct Private;
    Private* d;
};

}

Q_DECLARE_METATYPE(Nanogear::Method);

#endif // NANOGEAR_METHOD_H
