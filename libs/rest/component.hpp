/*
 * This file is part of the nanogear project
 *
 * (C) Copyright 2008 by Lorenzo Villani <lvillani@binaryhelix.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation;
 * version 3 of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */


#ifndef NANOGEAR_RESTCOMPONENT_HPP
#define NANOGEAR_RESTCOMPONENT_HPP

namespace std {
    template <class T> class vector<T>;
}

namespace nanogear {
namespace rest {

    
class component : public restlet {
public:
    component();
    ~component();
    
    std::vector<client> clients();
    std::vector<server> servers();
    std::vector<host> hosts();
    virtual_host default_host() const;
    
    void start();
    void stop();

    void set_log(const service::log& value);
    service::log log() const;

    void set_status(const service::status& value);
    service::status status() const;
	
    
private:
    std::vector<server> m_servers;
    std::vector<client> m_clients;
    std::vector<virtual_host> m_virtual_hosts;
    service::log m_log;
    service::status m_status;
};


}
}

#endif
