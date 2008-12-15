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

bool character_set::operator==(const character_set& other) const
{
    bool result = false;
    result = (other.name() == name());
    return result;
}

bool character_set::operator!=(const character_set& other) const
{
    return !(*this == other);
}

character_set character_set::value_of(const std::string& name) {
    if (name == ALL.name()) {
        return ALL;
    } else if (name == ISO_8859_1.name()) {
        return ISO_8859_1;
    } else if (name == US_ASCII.name()) {
        return US_ASCII;
    } else if (name == UTF_8.name()) {
        return UTF_8;
    } else if (name == UTF_16.name()) {
        return UTF_16;
    } else {
        return character_set(name);
    }
}

const character_set character_set::ALL("*", "All character sets");
const character_set character_set::ISO_8859_1("ISO-8859-1", "ISO/IEC 8859-1 or Latin 1 character set");
const character_set character_set::US_ASCII("US-ASCII", "US ASCII character set");
const character_set character_set::UTF_8("UTF-8", "UTF 8 character set");
const character_set character_set::UTF_16("UTF-16", "UTF 16 character set");

}
}
}
