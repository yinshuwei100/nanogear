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

#ifndef NANOGEAR_RESTRESPONSE_HPP
#define NANOGEAR_RESTRESPONSE_HPP

namespace std {
    class string;
}

namespace nanogear {
namespace rest {

/**
 @author
*/
class response {
public:
    response(const request&);
    ~response();

    std::list<method> allowed_methods();
    challenge_request challenge_request();
    std::list<cookie_settings> cookie_settings();
    std::list<dimension> dimensions();
    reference redirect_ref();
    request request();
    server_info server_info();
    status status();

    void redirect_permanent(const reference&);
    void redirect_permanent(const std::string&);

    void redirect_see_other(const reference&);
    void redirect_see_other(const std::string&);

    void redirect_temporary(const reference&);
    void redirect_temporary(const std::string&);

    void set_challenge_request(const challenge_request&);

    void set_redirect_ref(const reference&);
    void set_redirect_ref(const std::string&);

    void set_request(const request&);

    void set_status(const status&);
    void set_status(const status&, const std::string&);
};

}
}

#endif /* NANOGEAR_RESTRESPONSE_HPP */
