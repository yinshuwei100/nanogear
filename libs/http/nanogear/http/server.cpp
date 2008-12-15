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

#include "server.hpp"
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <istream>
using boost::bind;

namespace nanogear {
namespace http {

namespace detail {
class connection : public boost::enable_shared_from_this<connection> {
public:
    typedef boost::shared_ptr<connection> ptr;
    static ptr create(boost::asio::io_service* io_service, server* s) {
        return ptr(new connection(io_service, s));
    }
    boost::asio::ip::tcp::socket& socket() {
        return m_socket;
    }
    void handle_accept() {
        boost::asio::async_read_until(m_socket, m_request, "\r\n", bind(&connection::handle_request, this));
        m_server->start_accept();
    }
private:
    void handle_request() {
        std::string s;
        std::istream is(&m_request);
        is >> s;
        s = m_server->handle(s);
        boost::asio::write(m_socket, boost::asio::buffer(s.data(), s.length()));
    }
    connection(boost::asio::io_service* io_service, server* s) : m_socket(*io_service), m_server(s) {}
    server* m_server;
    boost::asio::streambuf m_request;
    boost::asio::ip::tcp::socket m_socket;
};
}

server::server(boost::asio::io_service* io_service, const boost::asio::ip::tcp::endpoint& end) : m_io_service(io_service), m_acceptor(*io_service), m_endpoint(end) {
    start_accept();
}

void server::start_accept() {
    detail::connection::ptr new_connection = detail::connection::create(m_io_service, this);
    m_acceptor.async_accept(new_connection->socket(), bind(&detail::connection::handle_accept, new_connection.get()));
}


}
}

