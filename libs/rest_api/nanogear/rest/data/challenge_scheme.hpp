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

#ifndef NANOGEAR_REST_DATA_CHALLENGE_SCHEME_HPP
#define NANOGEAR_REST_DATA_CHALLENGE_SCHEME_HPP

#include <string>
#include "metadata.hpp"

namespace nanogear {
namespace rest {
namespace data {

class challenge_scheme : public metadata {
public:
    challenge_scheme(const std::string& name = std::string(),
                     const std::string& technical_name = std::string(),
                     const std::string& description = std::string()) : 
                     m_technical_name(technical_name), metadata(name, description) {}
                     
    virtual ~challenge_scheme() {};

    bool operator==(const challenge_scheme&) const;
    bool operator!=(const challenge_scheme&) const;

    const std::string& name() const;
    void set_name(const std::string&);

    const std::string& technical_name() const;
    void set_technical_name(const std::string&);

    const std::string& description() const;
    void set_description(const std::string&);

    static challenge_scheme value_of(const std::string& name);

    static challenge_scheme custom;
    struct http {
        static challenge_scheme aws_s3;
        static challenge_scheme basic;
        static challenge_scheme digest;
        static challenge_scheme ntlm;
        static challenge_scheme oauth;
    };
    struct pop {
        static challenge_scheme basic;
        static challenge_scheme digest;
    };
    struct smtp { static challenge_scheme plain; };
private:
    std::string m_name;
    std::string m_technical_name;
    std::string m_description;
};

}
}
}

#endif /* NANOGEAR_REST_DATA_CHALLENGE_SCHEME_HPP */
