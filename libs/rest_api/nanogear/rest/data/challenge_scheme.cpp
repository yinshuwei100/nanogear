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

#include "challenge_scheme.hpp"

namespace nanogear {
namespace rest {
namespace data {

challenge_scheme::challenge_scheme(const std::string& name,
                                   const std::string& technical_name,
                                   const std::string& description)
: m_name(name), m_technical_name(technical_name), m_description(description)
{
}

bool challenge_scheme::operator==(const challenge_scheme& other) const {
    return (other.name() == name());
}

bool challenge_scheme::operator!=(const challenge_scheme& other) const {
    return !(*this == other);
}


const std::string& challenge_scheme::name() const
{
    return m_name;
}
void challenge_scheme::set_name(const std::string& name)
{
    m_name = name;
}

const std::string& challenge_scheme::technical_name() const
{
    return m_technical_name;
}
void challenge_scheme::set_technical_name(const std::string& technical_name)
{
    m_technical_name = technical_name;
}

const std::string& challenge_scheme::description() const
{
    return m_description;
}
void challenge_scheme::set_description(const std::string& description)
{
    m_description = description;
}


}
}
}
