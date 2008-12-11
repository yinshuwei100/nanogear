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

#ifndef NANOGEAR_REST_SERVER_HPP
#define NANOGEAR_REST_SERVER_HPP

#include <string>
#include <list>
#include <boost/shared_ptr.hpp>

#include "connector.hpp"
#include "controller.hpp"
#include "context.hpp"
#include "util/helper.hpp"
#include "data/protocol.hpp"

namespace nanogear {
namespace rest {
template <class> class server;

class abstract_server : public connector { // TODO: complete implementation
protected:
    abstract_server(const context&, const std::list<data::protocol>&, const int, const std::string&, const controller::ptr&);
    virtual ~abstract_server() {};
public:
    const std::string& address() const;
    const util::helper<abstract_server>::ptr& helper() const;
    int port() const;
    const controller::ptr& target() const;
    void operator()(const data::request&, const data::response&);
    bool has_target() const;
    void set_address(const std::string&);
    void set_port(int);
    void set_target(const controller::ptr&);
    void start();
    void stop();

private:
    std::string m_address;
    int m_port;
    controller::ptr m_target;
    util::helper<abstract_server>::ptr m_helper;
    template <class> friend class server;
};

template <class Engine>
class server : public abstract_server {
public:
    server(const context& cont, const std::list<data::protocol>& protos, const int port, const std::string& address, const controller::ptr& control)
      : abstract_server(cont, protos, port, address, control) {
        m_helper = Engine::create(ptr(this));
    }

    typedef boost::shared_ptr<server> ptr;

};
}
}

#endif /* NANOGEAR_REST_SERVER_HPP */

