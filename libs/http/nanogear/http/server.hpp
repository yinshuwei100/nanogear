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

#ifndef NANOGEAR_HTTP_SERVER_HPP
#define NANOGEAR_HTTP_SERVER_HPP
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>
#include <boost/function/function1.hpp>

namespace nanogear {
namespace http {

class server : private boost::noncopyable {
public:
    server(boost::asio::io_service*, const boost::asio::ip::tcp::endpoint&);
    boost::function1<std::string, const std::string&> handle;
    void start_accept();
private:
    boost::asio::io_service* m_io_service;
    boost::asio::ip::tcp::acceptor m_acceptor;
    boost::asio::ip::tcp::endpoint m_endpoint;
};

}
}

#endif /* NANOGEAR_HTTP_SERVER_HPP */

