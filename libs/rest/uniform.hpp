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

#ifndef NANOGEAR_RESTUNIFORM_HPP
#define NANOGEAR_RESTUNIFORM_HPP

namespace nanogear {
namespace rest {

namespace data {
class response;
}

/**
 *
 * @author Lorenzo Villani <lvillani@binaryhelix.net>
 */
class uniform {
public:
    uniform();
    ~uniform();

    response delete_resource(const reference&);
    response delete_resource(const std::string&);

    response get_resource(const reference&);
    response get_resource(const std::string&);

    response handle(const request&);
    response handle(const request&, const response&);

    response head(const reference&);
    response head(const std::string&);

    response options(const reference&);
    response options(const std::string&);

    response post(const reference&);
    response post(const std::string&);

    response put(const reference&);
    response put(const std::string&);
};

}
}

#endif /* NANOGEAR_RESTUNIFORM_HPP */
