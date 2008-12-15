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

#include "client.hpp"
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <istream>
using boost::bind;

namespace nanogear {
namespace http {

client::client(boost::asio::io_service* io_service, const boost::asio::ip::tcp::endpoint& end) : m_io_service(io_service), m_socket(*io_service), m_endpoint(end) {
    m_socket.connect(m_endpoint);
}

std::string client::handle(const std::string& request) {
    boost::asio::write(m_socket, boost::asio::buffer(request.data(), request.length()));
    boost::asio::read(m_socket, m_response);
    std::string s;
    std::istream is(&m_response);
    is >> s;
    return s;
}


}
}

