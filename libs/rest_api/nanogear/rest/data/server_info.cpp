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

#include "server_info.hpp"

namespace nanogear {
namespace rest {
namespace data {

const std::string& server_info::address() const
{
    return m_address;
}

void server_info::set_address(const std::string& address)
{
    m_address = address;
}

const std::string& server_info::agent() const
{
    return m_agent;
}

void server_info::set_agent(const std::string& agent)
{
    m_agent = agent;
}

int server_info::port() const
{
    return m_port;
}

void server_info::set_port(int port)
{
    m_port = port;
}

}
}
}
