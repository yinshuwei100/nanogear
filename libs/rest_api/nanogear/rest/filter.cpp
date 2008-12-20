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




#include "filter.hpp"

namespace nanogear {
namespace rest {

filter::filter(const context& c, funct n) : controller(c), m_next(n) {}

filter::funct& filter::next()
{
    return m_next;
}

bool filter::has_next()
{
    return m_next;
}

void filter::set_next(funct& next)
{
    m_next = next;
}

void filter::operator()(const data::request& req, const data::response& res)
{
    init(req, res);
    before_handle(req, res);
    do_handle(req, res);
    after_handle(req, res);
}

void filter::do_handle(const data::request& req, const data::response& res)
{
    if (has_next()) next()(req, res); else
    throw std::runtime_error("do_handle() without a next controller.");
}

}
}

