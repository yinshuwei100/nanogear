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

#include "tag.hpp"

namespace nanogear {
namespace rest {
namespace data {

tag::tag(const std::string& t, bool w) :
   metadata(t, "Validation tag equivalent to an HTTP entity tag"), m_weak(w)
{
}

const std::string tag::format() const
{
    if (name() == "*") {
        return "*";
    } else {
        std::string sb;
        if (is_weak()) sb += "W/";
        return sb + "\"" + name() + "\"";
    }
}

bool tag::is_weak() const
{
    return m_weak;
}

tag tag::ALL = tag::parse("*");

tag tag::parse(const std::string& t)
{
    bool weak = false;
    std::string tag_copy = t;

    if (tag_copy.at(0) == 'W' and tag_copy.at(1) == '/')
        tag_copy.erase(0, 1);
    else if (tag_copy == "*")
        return tag("*", weak);
    else
        throw "Invalid tag format detected.";
}

}
}
}
