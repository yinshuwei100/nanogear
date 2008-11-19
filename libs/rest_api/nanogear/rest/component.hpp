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




#ifndef NANOGEAR_REST_COMPONENT_HPP
#define NANOGEAR_REST_COMPONENT_HPP

#include <vector>
#include <boost/shared_ptr.hpp>
#include "controller.hpp"
#include "client.hpp"
#include "server.hpp"

namespace nanogear {
namespace rest {

    
class component : public controller {
public:
    component();
    ~component();
    
    const std::vector<client::ptr>& clients() const;
    const std::vector<server::ptr>& servers() const;
    const std::vector< boost::shared_ptr<host> >& hosts() const;
    const virtual_host& default_host() const;
    
    void start();
    void stop();

    void set_log(const service::log& value);
    const service::log& log() const;

    void set_status(const service::status& value);
    const service::status& status() const;

    typedef boost::shared_ptr<component> ptr;
    
private:
    service::log m_log;
    std::vector<server::ptr> m_servers;
    std::vector<client::ptr> m_clients;
    std::vector< boost::shared_ptr<virtual_host> > m_virtual_hosts;
    service::status m_status;
};


}
}

#endif /* NANOGEAR_REST_COMPONENT_HPP */
