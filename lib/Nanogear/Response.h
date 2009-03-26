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

#ifndef NANOGEAR_RESPONSE_H
#define NANOGEAR_RESPONSE_H

#include "Status.h"
#include <QMetaType>
#include <QDateTime>

namespace Nanogear {

namespace Resource {
class Representation;
}

class Response {
public:
    Response() : m_representation(0) { qRegisterMetaType<Response>(); }
    Response(const Status& s, const Resource::Representation* rep,
      const QDateTime& expires = QDateTime::currentDateTime())
        : m_status(s), m_representation(rep), m_expires(expires) { qRegisterMetaType<Response>(); }
    virtual ~Response() {}

    void setStatus(const Status& s)
        { m_status = s; }
    const Status& status()
        { return m_status; }

    void setRepresentation(const Resource::Representation* representation)
        { m_representation = representation; }
    const Resource::Representation* representation() const
        { return m_representation; }

    void setExpires(const QDateTime& expires)
        { m_expires = expires; }
    const QDateTime& expires() const
        { return m_expires; }
private:
    Status m_status;
    const Resource::Representation* m_representation;
    QDateTime m_expires;
};

}

Q_DECLARE_METATYPE(Nanogear::Response);

#endif /* NANOGEAR_RESPONSE_H */
