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



#include "protocol.hpp"

namespace nanogear {
namespace rest {
namespace data {

protocol::protocol(const std::string& scheme_name) :
    metadata(scheme_name, scheme_name + " Protocol")
{
    m_scheme_name = scheme_name;
    m_default_port = UNKNOWN_PORT;
}

protocol::protocol(const std::string& scheme_name, const std::string& name,
                   const std::string& description, int default_port) : metadata(name, description)
{
    m_scheme_name = scheme_name;
    m_default_port = default_port;
}

int protocol::default_port() const
{
    return m_default_port;
}

void protocol::set_default_port(int default_port)
{
    m_default_port = default_port;
}

const std::string& protocol::scheme_name() const
{
    return m_scheme_name;
}

void protocol::set_scheme_name(const std::string& scheme_name)
{
    m_scheme_name = scheme_name;
}


}
}
}
