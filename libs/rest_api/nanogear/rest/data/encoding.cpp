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

#include "encoding.hpp"

namespace nanogear {
namespace rest {
namespace data {

encoding encoding::value_of(const std::string& name)
{
    if (name == GZIP.name()) {
        return GZIP;
    } else if (name == ZIP.name()) {
        return ZIP;
    } else if (name == COMPRESS.name()) {
        return COMPRESS;
    } else if (name == DEFLATE.name()) {
        return DEFLATE;
    } else if (name == IDENTIFY.name()) {
        return IDENTIFY;
    } else {
        return encoding(name);
    }
}

// default encodings
// FIXME: these are not immutable objects
encoding encoding::ALL("*", "All encodings");
encoding encoding::GZIP("GZip compression");
encoding encoding::ZIP("Zip compression");
encoding encoding::COMPRESS("Common Unix compression");
encoding encoding::DEFLATE("Deflate compression using the zlib format");
encoding encoding::IDENTIFY("The default encoding without any transformation");

}
}
}
