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

template <class> class client;
class abstract_client : public connector {
protected:
    abstract_client(const context&, const std::list<data::protocol>&);
    virtual ~abstract_client() {};
public:
    util::helper<abstract_client>::ptr& get_helper();

    void operator()(const data::request&, const data::response&);

    void start();
    void stop();

private:
    util::helper<abstract_client>::ptr m_helper;
    template<class> friend class client;
};
 
template <class Engine>
class client : public connector {
public:
    client(const context& c = context(), const std::list<data::protocol>& p = std::list<data::protocol>()) :
      abstract_client(c, p) {
        if (p.size() != 0)
             this->abstract_client::m_helper = Engine::create(this);
    }
    typedef boost::shared_ptr<client> ptr;
};

}
}

#endif /* NANOGEAR_REST_DATA_HPP */
