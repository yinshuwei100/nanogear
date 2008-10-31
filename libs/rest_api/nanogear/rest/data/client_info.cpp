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

#include "client_info.hpp"

namespace nanogear {
namespace rest {
namespace data {

client_info::client_info()
{
    m_port = -1;
}


const std::list< preference<character_set> >& client_info::accepted_character_sets() const
{
    // TODO
}

const std::list< preference<encoding> >& client_info::accepted_encodings() const
{
    // TODO
}


const std::list< preference<language> >& client_info::accepted_languages() const
{
    // TODO
}


const std::list< preference<media_type> >& client_info::accepted_media_types() const
{
    // TODO
}

#if 0
const variant& client_info::preferred_variant(const std::list<variant>&,
                                              const language&)
{
    // TODO
}
#endif


const std::string& client_info::address() const
{
    return m_addresses.front();
}
void client_info::set_address(const std::string& address)
{
    m_addresses.insert(m_addresses.begin(), address);
}

const std::string& client_info::agent() const
{
    return m_agent;
}
void client_info::set_agent(const std::string& agent)
{
    m_agent = agent;
}

const int client_info::port() const
{
    return m_port;
}
void client_info::set_port(const int port)
{
    m_port = port;
}



}
}
}
