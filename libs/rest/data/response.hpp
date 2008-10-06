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

#include "request.hpp"
#include "method.hpp"
#include "challenge_request.hpp"
#include "reference.hpp"

#include <string>
#include <list>

namespace nanogear {
namespace rest {
namespace data {

/**
 @author
 */
class response {
public:
    response(const request&);
    ~response();

    std::list<method> allowed_methods();
    challenge_request get_challenge_request();
//    std::list<cookie_settings> cookie_settings(); // TODO
//    std::list<dimension> dimensions();
    reference redirect_ref();
    request get_request();
//    server_info get_server_info();
//    status get_status();

    void redirect_permanent(const reference&);
    void redirect_permanent(const std::string&);

    void redirect_see_other(const reference&);
    void redirect_see_other(const std::string&);

    void redirect_temporary(const reference&);
    void redirect_temporary(const std::string&);

    void set_challenge_request(const challenge_request&);

    void set_redirect_ref(const reference&);
    void set_redirect_ref(const std::string&);

//    void set_request(const request&);

//    void set_status(const status&);
//    void set_status(const status&, const std::string&);
};

}
}
}

#endif /* NANOGEAR_REST_RESPONSE_HPP */
