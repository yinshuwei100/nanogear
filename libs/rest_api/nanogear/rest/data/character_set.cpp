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



#include <string>

#include "character_set.hpp"

namespace nanogear {
namespace rest {
namespace data {

#define add_character_set(x, y, z) character_set character_set::x(y, z)
add_character_set(all, "*", "All character sets");
add_character_set(iso_8859_1, "ISO-8859-1", "ISO/IEC 8859-1 or Latin 1 character set");
add_character_set(us_ascii, "US-ASCII", "US ASCII character set");
add_character_set(utf_8, "UTF-8", "UTF 8 character set");
add_character_set(utf_16, "UTF-16", "UTF 16 character set");
#undef add_character_set

character_set& character_set::value_of(const std::string& name) {
    #define character_case(x) if (name == x.name()) return x
    character_case(all);
    character_case(iso_8859_1);
    character_case(us_ascii);
    character_case(utf_8);
    character_case(utf_16);
    #undef character_case
    return all;
}

}
}
}
