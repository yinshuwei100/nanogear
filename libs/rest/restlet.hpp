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
