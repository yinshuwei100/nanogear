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

#ifndef NANOGEAR_REST_ROUTER_HPP
#define NANOGEAR_REST_ROUTER_HPP

#include <list>

#include "route.hpp"
#include "controller.hpp"

namespace nanogear {
namespace rest {

/*!
 * Controller routing calls to one of the attached routes. Each route can compute
 * an affinity score for each call depending on various criteria. The attach()
 * method allow the creation of routes based on URI patterns matching the
 * beginning of a the resource reference's remaining part.<br>
 * <br>
 * In addition, several routing modes are supported, implementing various
 * algorithms:
 * <ul>
 * <li>Best match (default)</li>
 * <li>First match</li>
 * <li>Last match</li>
 * <li>Random match</li>
 * <li>Round robin</li>
 * <li>Custom</li>
 * </ul>
 * <br>
 * Note that for routes using URI patterns will update the resource reference's
 * base reference during the routing if they are selected. It is also important
 * to know that the routing is very strict about path separators in your URI
 * patterns.
 *
 * This class is not (yet) guaranteed to be thread safe
 *
 * \author Lorenzo Villani
 */
class router : public controller {
public:
    router();
    virtual ~router() {}

    static const int BEST = 1;
    static const int CUSTOM = 6;
    static const int FIRST = 2;
    static const int LAST = 3;
    static const int NEXT = 4;
    static const int RANDOM = 5;
private:
    int m_default_matching_mode;
    bool m_default_match_query;
    int m_max_attemps;
    float m_required_score;
    long m_retry_delay;
    std::list<route> m_routes;
};

}
}

#endif