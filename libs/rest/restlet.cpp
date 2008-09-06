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

#include "restlet.hpp"
#include <stdexcept>

namespace nanogear {
namespace rest {

restlet::restlet(context c) : m_context(c), m_started(false)
{
}

bool restlet::started()
{
    return m_started;
}

bool restlet::stopped()
{
    return !started();
}

void restlet::set_context(context c)
{
    m_context = c;
}

context restlet::get_context()
{
    return m_context;
}

void restlet::start()
{
    m_started = true;
}

void restlet::stop()
{
    m_started = false;
}

void restlet::handle(data::request req, data::response res)
{
    init(req, res);
}

void restlet::init(data::request req, data::response res)
{
    if (stopped()) start()
    if (stopped() or (!started())) throw std::logic_error("Failed to start() service.");
}

}
}
