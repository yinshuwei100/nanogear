/*
 * Nanogear - C++ web development framework
 *
 * This library is based on Restlet (R) <http://www.restlet.org> by Noelios Technologies
 * Copyright (C) 2005-2008 by Noelios Technologies <http://www.noelios.com>
 * Restlet is a registered trademark of Noelios Technologies. All other marks and
 * trademarks are property of their respective owners.
 *
 * Copyright (C) 2008 Lorenzo Villani.
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

#include <string>

#include "cookie_setting.hpp"

namespace nanogear {
namespace rest {
namespace data {

cookie_setting::cookie_setting()
{
    cookie_setting(0, "", "", "", "");
}

cookie_setting::cookie_setting(const std::string& name, const std::string& value)
{
    cookie_setting(0, name, value);
}

cookie_setting::cookie_setting(int version, const std::string& name,
                               const std::string& value)
{
    cookie_setting(version, name, value, "", "");
}

cookie_setting::cookie_setting(int version, const std::string& name,
                       const std::string& value, const std::string& path,
                       const std::string& domain) : cookie(version, name, value,
                                                           path, domain)
{
    m_max_age = -1;
    m_secure = false;
}

const std::string& cookie_setting::comment() const
{
    return m_comment;
}

void cookie_setting::set_comment(const std::string& comment)
{
    m_comment = comment;
}

int cookie_setting::max_age() const
{
    return m_max_age;
}

void cookie_setting::set_max_age(int max_age)
{
    m_max_age = max_age;
}

bool cookie_setting::secure() const
{
    return m_secure;
}

void cookie_setting::set_secure(bool secure)
{
    m_secure = secure;
}

}
}
}
