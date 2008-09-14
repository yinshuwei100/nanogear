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




#ifndef NANOGEAR_RESTRESTLET_HPP
#define NANOGEAR_RESTRESTLET_HPP
#include "uniform.hpp"
#include "context.hpp"
#include <data/response.hpp>

namespace nanogear {
namespace rest {

/**
 *
 * @author Michael Howell <mhowell123@gmail.com>
 */
class restlet : public uniform {
public:
    restlet(context);

    // TODO: get_logger().
    void handle(data::request, data::response);
    bool started();
    bool stopped();
    void set_context(context c);
    context get_context();
    void start();
    void stop();

protected:
    void init(data::request, data::response);

private:
    context m_context;
    bool m_started;

};

}
}

#endif /* NANOGEAR_RESTUNIFORM_HPP */
