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

#ifndef NANOGEAR_STATUS_H
#define NANOGEAR_STATUS_H

namespace Nanogear {

class Status {
public:
    Status(int code) : m_code(code) {
        switch(m_code) {
            case 200: m_name = "OK"; break;
            case 404: m_name = "Not Found"; break;
        }
    }
    int code() const
        { return m_code; }
    void setCode(int stat)
        { m_code = stat; }
    const QString& name() const
        { return m_name; }
    void setName(const QString& name)
        { m_name = name; }
private:
    int m_code;
    QString m_name;
};

}

#endif /* NANOGEAR_STATUS_H */
