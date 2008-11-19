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

#ifndef NANOGEAR_REST_DATA_HPP
#define NANOGEAR_REST_DATA_HPP

#include <list>
#include <boost/shared_ptr.hpp>
#include "data/protocol.hpp"
#include "connector.hpp"
#include "util/helper.hpp"

namespace nanogear {
namespace rest {
 
class client : public connector {
public:
    client(const context& = context(), const std::list<data::protocol>& = std::list<data::protocol>());
    ~client();
    util::helper::ptr& get_helper();

    void operator()(const data::request&, const data::response&);

    void start();
    void stop();
    typedef boost::shared_ptr<client> ptr;

private:
    util::helper::ptr m_helper;
};

}
}

#endif /* NANOGEAR_REST_DATA_HPP */
