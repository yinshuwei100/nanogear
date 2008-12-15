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



#ifndef NANOGEAR_REST_RESPONSE_HPP
#define NANOGEAR_REST_RESPONSE_HPP

#include <set>
#include <list>
#include <string>

#include "method.hpp"
#include "status.hpp"
#include "message.hpp"
#include "request.hpp"
#include "dimension.hpp"
#include "reference.hpp"
#include "server_info.hpp"
#include "cookie_setting.hpp"
#include "challenge_request.hpp"

namespace nanogear {
namespace rest {
namespace data {

/**
 @author
 */
class response : public message {
public:
    //response() {};
    //response(const request& request) : m_request(request) {};
    virtual ~response() {};

    const std::set<data::method>& allowed_methods() const;
    void set_allowed_methods(const std::set<data::method>&);
    
    const std::set<data::dimension>& dimension() const;
    void set_dimension(const std::set<data::dimension>&);
    
    const std::list<data::cookie_setting>& cookie_settings() const;
    void set_cookie_settings(const std::list<data::cookie_setting>&);
    
    const data::reference& redirect_ref() const;
    void set_redirect_ref(const data::reference&);

    const data::request& request() const;
    void set_request(const data::request&);
    void set_request(const std::string&);

    const data::server_info& server_info() const;
    void set_server_info(const data::server_info&);

    const data::status& status() const;
    void set_status(const data::status&);

private:
    std::set<data::method> m_allowed_methods;
    std::set<data::dimension> m_dimensions;
    std::list<data::cookie_setting> m_cookie_settings;
    data::reference m_redirect_ref;
    data::challenge_request m_challenge_request;
    data::request m_request;
    data::server_info m_server_info;
    data::status m_status;
};

}
}
}

#endif /* NANOGEAR_REST_RESPONSE_HPP */
