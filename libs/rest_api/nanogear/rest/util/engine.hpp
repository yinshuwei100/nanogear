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

#ifndef NANOGEAR_REST_UTIL_HELPER_FACTORY_HPP
#define NANOGEAR_REST_UTIL_HELPER_FACTORY_HPP

#include <boost/shared_ptr.hpp>

#include "helper.hpp"
#include "../application.hpp"
#include "../client.hpp"
//#include "../component.hpp"
#include "../server.hpp"

namespace nanogear {
namespace rest {
namespace util {
class engine {
public:
    typedef boost::shared_ptr<engine> ptr;
    static ptr instance();
    virtual helper<application>::ptr create(const application&) = 0;
    virtual helper<client>::ptr create(const client&) = 0;
    //virtual helper<component>::ptr create(const component&) = 0;
    virtual helper<server>::ptr create(const server&) = 0;

private:
    static boost::shared_ptr<engine> s_instance;
};
}
}
}


#endif /* NANOGEAR_REST_UTIL_HELPER_HPP */

