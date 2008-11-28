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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "handler.hpp"

namespace nanogear {
namespace rest {

handler::handler(const context& c, const data::request& req, const data::response& res)
    : m_context(c), m_request(req), m_response(res) {}

bool handler::allow_delete() const
{
    return false;
}
bool handler::allow_get() const
{
    return false;
}
bool handler::allow_head() const
{
    return allow_get();
}
bool handler::allow_options() const
{
    return true;
}
bool handler::allow_post() const
{
    return false;
}
bool handler::allow_put() const
{
    return false;
}
const context& handler::get_context() const
{
    return m_context;
}
const data::request& handler::get_request() const
{
    return m_request;
}
const data::response& handler::get_response() const
{
    return m_response;
}
}
}
