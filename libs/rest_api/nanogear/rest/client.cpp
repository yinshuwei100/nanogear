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

#include "client.hpp"
#include "util/engine.hpp"

namespace nanogear {
namespace rest {

client::client(const context& c, const std::list<data::protocol>& p) : connector(c, p)
{
    if ((p.size() != 0) && util::engine::instance())
        m_helper = util::engine::instance()->create(ptr(this));
}

util::helper<client>::ptr& client::get_helper()
{
    return m_helper;
}

void client::operator()(const data::request& req, const data::response& res)
{
    init(req, res);
    if (get_helper()) (*get_helper())(req, res);
}

void client::start()
{
    if (stopped()) {
        connector::start();
        if (get_helper()) get_helper()->start();
    }
}

void client::stop()
{
    if (started()) {
        if (get_helper()) get_helper()->stop();
        connector::stop();
    }
}

}
}
