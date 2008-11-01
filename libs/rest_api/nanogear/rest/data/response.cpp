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


#include "response.hpp"

namespace nanogear {
namespace rest {
namespace data {

const std::set<data::method>& response::allowed_methods() const
{
    return m_allowed_methods;
}

void response::set_allowed_methods(const std::set<data::method>& allowed_methods)
{
    m_allowed_methods = allowed_methods;
}

const std::set<data::dimension>& response::dimension() const
{
    return m_dimensions;
}

void response::set_dimension(const std::set<data::dimension>& dimensions)
{
    m_dimensions = dimensions;
}

const std::list<data::cookie_setting>& response::cookie_settings() const
{
    return m_cookie_settings;
}

void response::set_cookie_settings(const std::list<data::cookie_setting>& cookie_settings)
{
    m_cookie_settings = cookie_settings;
}

const data::reference& response::redirect_ref() const
{
    return m_redirect_ref;
}

void response::set_redirect_ref(const data::reference& redirect_ref)
{
    m_redirect_ref = redirect_ref;
}
void response::set_redirect_ref(const std::string& redirect_uri)
{
    // TODO: complete implementation
}

const data::server_info& response::server_info() const
{
    return m_server_info;
}

void response::set_server_info(const data::server_info& server_info)
{
    m_server_info = server_info;
}

const data::status& response::status() const
{
    return m_status;
}

void response::set_status(const data::status& status)
{
    m_status = status;
}

}
}
}
