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

#ifndef NANOGEAR_REST_DATA_CHARACTER_SET_HPP
#define NANOGEAR_REST_DATA_CHARACTER_SET_HPP

#include <string>
#include "metadata.hpp"

namespace nanogear {
namespace rest {
namespace data {

class character_set : public metadata {
public:
    character_set(const std::string& name = std::string()) : metadata(name) {};
    character_set(const std::string& name, const std::string& description) :
        metadata(name, description) {};
    virtual ~character_set() {};

    bool operator==(const character_set&) const;
    bool operator!=(const character_set&) const;

    static character_set value_of(const std::string& name);

    static const character_set ALL;
    static const character_set ISO_8859_1;
    static const character_set US_ASCII;
    static const character_set UTF_8;
    static const character_set UTF_16;
};

}
}
}

#endif /* NANOGEAR_REST_DATA_CHARACTER_SET_HPP */
