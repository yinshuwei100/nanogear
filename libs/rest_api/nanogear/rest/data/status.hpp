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

#ifndef NANOGEAR_REST_DATA_STATUS_HPP
#define NANOGEAR_REST_DATA_STATUS_HPP

#include "metadata.hpp"

#include <string>

namespace nanogear {
namespace rest {
namespace data {

class status : public metadata {
public:
    static bool client_error(int);
    static bool connector_error(int);
    static bool error(int);
    static bool info(int);
    static bool redirection(int);
    static bool server_error(int);
    static bool success(int);

    status(int = SUCCESS_OK);
    status(int, const std::string&, const std::string&, const std::string& uri = std::string());
    int code() const;
    operator int() const;
    const std::string& uri() const;

    enum codes {
        INFO_CONTINUE = 100,
        INFO_SWITCHING_PROTOCOL = 101,
        INFO_PROCESSING = 102,
        SUCCESS_OK = 200,
        SUCCESS_CREATED = 201,
        SUCCESS_ACCEPTED = 202,
        SUCCESS_NON_AUTHORITATIVE = 203,
        SUCCESS_NO_CONTENT = 204,
        SUCCESS_RESET_CONTENT = 205,
        SUCCESS_PARTIAL_CONTENT = 206,
        SUCCESS_MULTI_STATUS = 207,
        REDIRECTION_MULTIPLE_CHOICES = 300,
        REDIRECTION_PERMANENT = 301,
        REDIRECTION_FOUND = 302,
        REDIRECTION_SEE_OTHER = 303,
        REDIRECTION_NOT_MODIFIED = 304,
        REDIRECTION_USE_PROXY = 305,
        REDIRECTION_TEMPORARY = 307,
        CLIENT_ERROR_BAD_REQUEST = 400,
        CLIENT_ERROR_UNAUTHORIZED = 401,
        CLIENT_ERROR_PAYMENT_REQUIRED = 402,
        CLIENT_ERROR_FORBIDDEN = 403,
        CLIENT_ERROR_NOT_FOUND = 404,
        CLIENT_ERROR_METHOD_NOT_ALLOWED = 405,
        CLIENT_ERROR_NOT_ACCEPTABLE = 406,
        CLIENT_ERROR_PROXY_AUTHENTIFICATION_REQUIRED = 407,
        CLIENT_ERROR_REQUEST_TIMEOUT = 408,
        CLIENT_ERROR_CONFLICT = 409,
        CLIENT_ERROR_GONE = 410,
        CLIENT_ERROR_LENGTH_REQUIRED = 411,
        CLIENT_ERROR_PRECONDITION_FAILED = 412,
        CLIENT_ERROR_REQUEST_ENTITY_TOO_LARGE = 413,
        CLIENT_ERROR_REQUEST_URI_TOO_LONG = 414,
        CLIENT_ERROR_UNSUPPORTED_MEDIA_TYPE = 415,
        CLIENT_ERROR_REQUESTED_RANGE_NOT_SATISFIABLE = 416,
        CLIENT_ERROR_EXPECTATION_FAILED = 417,
        CLIENT_ERROR_UNPROCESSABLE_ENTITY = 422,
        CLIENT_ERROR_LOCKED = 423,
        CLIENT_ERROR_FAILED_DEPENDENCY = 424,
        SERVER_ERROR_INTERNAL = 500,
        SERVER_ERROR_NOT_IMPLEMENTED = 501,
        SERVER_ERROR_BAD_GATEWAY = 502,
        SERVER_ERROR_SERVICE_UNAVAILABLE = 503,
        SERVER_ERROR_GATEWAY_TIMEOUT = 504,
        SERVER_ERROR_VERSION_NOT_SUPPORTED = 505,
        SERVER_ERROR_INSUFFICIENT_STORAGE = 507,
        CONNECTOR_ERROR_CONNECTION = 1000,
        CONNECTOR_ERROR_COMMUNICATION = 1001,
        CONNECTOR_ERROR_INTERNAL = 1002,
    };

private:
    int m_code;
    std::string m_uri;
};

}
}
}

#endif /* NANOGEAR_REST_DATA_STATUS_HPP */
