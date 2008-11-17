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



#include <string>

#include "method.hpp"

namespace nanogear {
namespace rest {
namespace data {

#define BASE_HTTP http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html
#define BASE_WEBDAV http://www.webdav.org/specs/rfc2518.html

method::method(const std::string& name, const std::string& description, const std::string& uri) : metadata(name, description), m_uri(uri) {}

const std::string& uri() const
{
    return m_uri;
}

method method::CONNECT("CONNECT",
                       "Used with a proxy that can dynamically switch to being a tunnel",
                       "##BASE_HTTP###sec9.9");

method method::COPY("COPY",
                    "Creates a duplicate of the source resource, identified by"
                    "the Request-URI, in the destination resource, identified"
                    "by the URI in the Destination header",
                    "##BASE_WEBDAV###METHOD_COPY");

method method::DELETE("DELETE",
                      "Requests that the origin server deletes the resource"
                      "identified by the request URI",
                      "##BASE_HTTP###sec9.7");

method method::GET("GET",
                   "Retrieves whatever information (in the form of an entity)"
                   "that is identified by the request URI",
                   "##BASE_HTTP###sec9.3");

method method::HEAD("HEAD",
                    "Identical to GET except that the server must not return"
                    "a message body in the response",
                    "##BASE_HTTP###sec9.4");

method method::LOCK("LOCK",
                    "Used to take out a lock of any access type (WebDAV)",
                    "##BASE_WEBDAV###METHOD_LOCK");

method method::MKCOL("MKCOL",
                     "Used to create a new collection (WebDAV)",
                     "##BASE_WEBDAV###METHOD_MKCOL");

method method::MOVE("MOVE",
                    "Logical equivalent of a copy, followed by consistency maintenance"
                    "processing, followed by a delete of the source (WebDAV)",
                    "##BASE_WEBDAV###METHOD_MOVE");


method OPTIONS("OPTIONS",
               "Requests for information about the communication options available"
               "on the request/response chain identified by the URI",
               "##BASE_HTTP###sec9.2");

method method::POST("POST",
                    "Requests that the origin server accepts the entity enclosed"
                    "in the request as a new subordinate of the resource identified by the request URI",
                    "##BASE_HTTP###sec9.5");


method method::PROPFIND("PROPFIND",
                        "Retrieves properties defined on the resource identified by the"
                        "request URI",
                        "##BASE_WEBDAV###METHOD_PROPFIND");

method method::PROPPATCH("PROPPATCH",
                         "Processes instructions specified in the request body to set"
                         "and/or remove properties defined on the resource identified"
                         "by the request URI",
                         "##BASE_WEBDAV###METHOD_PROPPATCH");

method method::PUT("PUT",
                   "Requests that the enclosed entity be stored under the"
                   "supplied request URI",
                   "##BASE_HTTP###sec9.6");

method method::TRACE("TRACE",
                     "Used to invoke a remote, application-layer loop-back of"
                     "the request message",
                     "##BASE_HTTP###sec9.8");

method method::UNLOCK("UNLOCK",
                      "Removes the lock identified by the lock token from the request URI,"
                      "and allother resources included in the lock",
                      "##BASE_WEBDAV###METHOD_UNLOCK");

method method::value_of(const std::string& value)
{
    #define cas(x) if (value == x.name()) return x
    cas(GET);
    cas(POST);
    cas(HEAD);
    cas(OPTIONS);
    cas(PUT);
    cas(DELETE);
    cas(CONNECT);
    cas(COPY);
    cas(LOCK);
    cas(MKCOL);
    cas(MOVE);
    cas(PROPFIND);
    cas(PROPPATCH);
    cas(TRACE);
    cas(UNLOCK);
    return method(value);
    #undef cas
}

}
}
}
