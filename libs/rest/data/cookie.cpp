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

#include "cookie.hpp"

namespace nanogear {
namespace rest {
namespace data {

cookie::cookie(const std::string& name, const std::string& value)
{
    cookie(0, name, value, "", "");
}

cookie::cookie(int version, const std::string& name, const std::string& value)
{
    cookie(version, name, value, "", "");
}

cookie::cookie(int version, const std::string& name, const std::string& value,
               const std::string& path, const std::string& domain)
{
    m_version = version;
    m_name = name;
    m_value = value;
    m_path = path;
    m_domain = domain;
}

bool cookie::operator==(const cookie& other)
{
    bool ret = false;
    ret = (version() == other.version());
    ret = (name() == other.name());
    ret = (value() == other.value());
    ret = (path() == other.path());
    ret = (domain() == other.domain());
    return ret;
}

bool cookie::operator!=(const cookie& other)
{
    return !(*this == other);
}

int cookie::version()
{
    return m_version;
}
void cookie::set_version(int version)
{
    m_version = version;
}


const std::string& cookie::name()
{
    return m_name;
}
void cookie::set_name(const std::string& name)
{
    m_name = name;
}

const std::string& cookie::value()
{
    return m_value;
}
void cookie::set_value(const std::string& value)
{
    m_value = value;
}

const std::string& cookie::path()
{
    return m_path;
}
void cookie::set_path(const std::string& path)
{
    m_path = path;
}

const std::string& cookie::domain()
{
    return m_domain;
}
void cookie::set_domain(const std::string& domain)
{
    m_domain = domain;
}


}
}
