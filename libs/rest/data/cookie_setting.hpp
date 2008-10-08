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

#ifndef NANOGEAR_REST_DATA_COOKIE_SETTING_HPP
#define NANOGEAR_REST_DATA_COOKIE_SETTING_HPP

#include "cookie.hpp"

#include <string>

namespace nanogear {
namespace rest {
namespace data {

class cookie_setting : public cookie
{
public:
    cookie_setting(int version = 0, std::string name = std::string(), std::string value = std::string(), std::string path = std::string(), std::string domain = std::string());
    cookie_setting(std::string& name, std::string& value);
    bool equals(void*); // ... or should I use something else?
    std::string get_comment();
    std::string get_description();
    int get_max_age();
    int hash_code();
    bool is_secure();
    void set_comment(std::string&);
    void set_max_age(int);
    void set_secure(bool);

private:
    std::string comment;
    int max_age;
    bool secure;
};

}
}
}

#endif /* NANOGEAR_REST_DATA_COOKIE_SETTING_HPP */
