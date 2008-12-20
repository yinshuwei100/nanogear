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

#include <map>
#include <string>
#include "message.hpp"

namespace nanogear {
namespace rest {
namespace data {

const std::map<std::string, std::string>& message::attributes() const
{
    return m_attributes;
}

const resource::representation::ptr& message::entity() const
{
    return m_entity;
}

void message::set_entity(const resource::representation::ptr& representation)
{
    m_entity = representation;
}

void message::set_entity(const std::string& value,
                         const nanogear::rest::data::media_type& media_type) {
    // TODO: build a string representation from value and media_type
}

bool message::is_entity_available() const
{
    // FIXME: In an ideal world we would check even if the entity has data in it
    // just return a boolean indicating if the entity is available
    return m_entity->is_available();
}

}
}
}
