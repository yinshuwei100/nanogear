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

#include "application.hpp"

namespace nanogear {
namespace rest {

application::application()
{
}

application::application(const context& c) : controller(c)
{
}


application::~application()
{
}

// Getters and setters follows
const std::string& application::description() const
{
    return m_description;
}
void application::set_description(const std::string& value)
{
    m_description = value;
}

const std::string& application::author() const
{
    return m_author;
}
void application::set_author(const std::string& value)
{
    m_author = value;
}

const std::string& application::name() const
{
    return m_name;
}
void application::set_name(const std::string& value)
{
    m_name = value;
}


const std::string& application::owner() const
{
    return m_owner;
}
void application::set_owner(const std::string& value)
{
    m_owner = value;
}

#if 0
service::connector application::connector() const
{
    return m_connector;
}
void application::set_connector(const service::connector& value)
{
    m_connector = value;
}


service::converter application::converter() const
{
    return m_converter;
}
void application::set_converter(const service::converter& value)
{
    m_converter = value;
}


service::decoder application::decoder() const
{
    return m_decoder;
}
void application::set_decoder(const service::decoder& value)
{
    m_decoder = value;
}


service::status application::status() const
{
    return m_status;
}
void application::set_status(const service::status& value)
{
    m_status = value;
}


service::tunnel application::tunnel() const
{
    return m_tunnel;
}
void application::set_tunnel(const service::tunnel& value)
{
    m_tunnel = value;
}

void application::set_metadata(const service::metadata& value)
{
    m_metadata = value;
}
#endif

} // end
}
