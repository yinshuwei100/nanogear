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

#include "character_set.hpp"

namespace nanogear {
namespace rest {
namespace data {

character_set::character_set(const std::string& name) {
    // FIXME: get 'name' as uppercase
    m_name = name;
}

character_set::character_set(const std::string& name,
                             const std::string& description)
{
    character_set(name);
    m_description = description;
}

bool character_set::operator==(const character_set& other) {
    return (other.name() == name());
}

bool character_set::operator!=(const character_set& other) {
    return !(*this == other);
}


const std::string& character_set::name()
{
    return m_name;
}
void character_set::set_name(const std::string& name)
{
    m_name = name;
}

const std::string& character_set::description()
{
    return m_description;
}
void character_set::set_description(const std::string& description)
{
    m_description = description;
}


}
}
}
