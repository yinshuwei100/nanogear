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

#include "status.hpp"

#include <sstream>

namespace nanogear {
namespace rest {
namespace data {

#define BASE_HTTP http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html
#define BASE_WEBDAV http://www.webdav.org/specs/rfc2518.html
#define BASE_RESTLET http://www.restlet.org/documentation/1.0/api/

bool status::client_error(int stat)
{
    if ((stat >= 400) && (stat < 500)) return true;
    return false;
}

bool status::connector_error(int stat)
{
    if ((stat >= 1000) && (stat < 1100)) return true;
    return false;
}

bool status::error(int stat)
{
    return connector_error(stat) or client_error(stat);
}

bool status::info(int stat)
{
    if ((stat >= 100) && (stat < 200)) return true;
    return false;
}

bool status::redirection(int stat)
{
    if ((stat >= 300) && (stat < 400)) return true;
    return false;
}

bool status::server_error(int stat)
{
    if ((stat >= 500) && (stat < 600)) return true;
    return false;
}

bool status::success(int stat)
{
    if ((stat >= 200) && (stat < 300))
        return true;
    return false;
}

status::status(int stat)
{
    switch (stat) {
    case INFO_CONTINUE: status(stat, "Continue", "The client should continue with its request", "##BASE_HTTP###sec10.1.1"); break;
    case INFO_SWITCHING_PROTOCOL: status(stat, "Switch Protocols", "The server is willing to change the application protocol being used on this connection", "##BASE_HTTP###sec10.1.2"); break;
    case INFO_PROCESSING: status(stat, "Processing", "Interim response used to inform the client that the server has accepted the complete request, but has not yet completed it", "##BASE_WEBDAV###STATUS_102"); break;
    case SUCCESS_OK: status(stat, "OK", "The request has succeeded", "##BASE_HTTP###sec10.2.1"); break;
    case SUCCESS_CREATED: status(stat, "Created", "The request has been fulfilled and resulted in a new resource being created", "##BASE_HTTP###sec10.2.2"); break;
    case SUCCESS_ACCEPTED: status(stat, "Accepted", "The request has been accepted for processing, but theprocessing has not been completed", "##BASE_HTTP###sec10.2.3"); break;
    case SUCCESS_NON_AUTHORITATIVE: status(stat, "Non-Authorative Information", "The returned metainformation is not the definitive set as available from the origin server", "##BASE_HTTP###sec10.2.4"); break;
    case SUCCESS_NO_CONTENT: status(stat, "No Content", "The server has fulfilled the request but does not need to return an entity-body, and might want to return updated metainformation", "##BASE_HTTP####sec10.2.5"); break;
    case SUCCESS_RESET_CONTENT: status(stat, "Reset Content", "The server has fulfilled the request and the user agent should reset the document view which caused the request to be sent", "##BASE_HTTP####sec10.2.6"); break;
    case SUCCESS_PARTIAL_CONTENT: status(stat, "Partial Content", "The server has fulfilled the partial get request for the resource", "##BASE_HTTP####sec10.2.7"); break;
    case SUCCESS_MULTI_STATUS: status(stat, "Multi-Status", "Provides status for multiple independent operations", "##BASE_WEBDAV###STATUS_207"); break;
    case REDIRECTION_MULTIPLE_CHOICES: status(stat, "Multiple Choices", "The requested resource corresponds to any one of a set of representations", "##BASE_HTTP####sec10.3.1"); break;
    case REDIRECTION_PERMANENT: status(stat, "Moved Permanently", "The requested resource has been assigned a new permanent URI", "##BASE_HTTP###sec10.3.2"); break;
    case REDIRECTION_FOUND: status(stat, "Found", "The requested resource can be found under a different URI", "##BASE_HTTP###sec10.3.3"); break;
    case REDIRECTION_SEE_OTHER: status(stat, "See Other", "The response to the request can be found under a different URI", "##BASE_HTTP###sec10.3.4"); break;
    case REDIRECTION_NOT_MODIFIED: status(stat, "Not Modified", "The client has performed a conditional GET request and the document has not been modified", "##BASE_HTTP###sec10.3.5"); break;
    case REDIRECTION_USE_PROXY: status(stat, "Use Proxy", "The requested resource must be accessed through the proxy given by the location field", "##BASE_HTTP###sec10.3.6"); break;
    case REDIRECTION_TEMPORARY: status(stat, "Temporary Redirect", "The requested resource resides temporarily under a different URI", "##BASE_HTTP###sec10.3.8"); break;
    case CLIENT_ERROR_BAD_REQUEST: status(stat, "Bad Request", "The request could not be understood by the server dueto malformed syntax", "##BASE_HTTP###sec10.4.1"); break;
    case CLIENT_ERROR_UNAUTHORIZED: status(stat, "Unauthorized", "The request requires user authentication", "##BASE_HTTP###sec10.4.2"); break;
    case CLIENT_ERROR_PAYMENT_REQUIRED: status(stat, "Payment Required", "This code is reserved for future use", "##BASE_HTTP###sec10.4.3"); break;
    case CLIENT_ERROR_FORBIDDEN: status(stat, "Forbidden", "The server understood the request, but is refusing tofulfill it", "##BASE_HTTP###sec10.4.4"); break;
    case CLIENT_ERROR_NOT_FOUND: status(stat, "Not Found", "The server has not found anything matching the request URI", "##BASE_HTTP###sec10.4.5"); break;
    case CLIENT_ERROR_METHOD_NOT_ALLOWED: status(stat, "Method Not Allowed", "The method specified in the request is not allowed for the resource identified by the request URI", "##BASE_HTTP###sec10.4.6"); break;
    case CLIENT_ERROR_NOT_ACCEPTABLE: status(stat, "Not Acceptable", "The resource identified by the request is only capable of generating response entities which have content characteristics not acceptable according to the accept headers sent in the request", "##BASE_HTTP###sec10.4.7"); break;
    case CLIENT_ERROR_PROXY_AUTHENTIFICATION_REQUIRED: status(stat, "Proxy Authentication Required", "This code is similar to Unauthorized, but indicates that the client must first authenticate itself with the proxy", "##BASE_HTTP###sec10.4.8"); break;
    case CLIENT_ERROR_REQUEST_TIMEOUT: status(stat, "Request Timeout", "The client did not produce a request within the time that the server was prepared to wait", "##BASE_HTTP###sec10.4.9"); break;
    case CLIENT_ERROR_CONFLICT: status(stat, "Conflict", "The request could not be completed due to a conflict with the current state of the resource", "##BASE_HTTP###sec10.4.10"); break;
    case CLIENT_ERROR_GONE: status(stat, "Gone", "The requested resource is no longer available at the server and no forwarding address is known", "##BASE_HTTP###sec10.4.11"); break;
    case CLIENT_ERROR_LENGTH_REQUIRED: status(stat, "Length Required", "The server refuses to accept the request without a defined content length", "##BASE_HTTP###sec10.4.12"); break;
    case CLIENT_ERROR_PRECONDITION_FAILED: status(stat, "Precondition Failed", "The precondition given in one or more of the request header fields evaluated to false when it was tested on the server", "##BASE_HTTP###sec10.4.13"); break;
    case CLIENT_ERROR_REQUEST_ENTITY_TOO_LARGE: status(stat, "Request Entity Too Large", "The server is refusing to process a request because the request entity is larger than the server is willing or able to process", "##BASE_HTTP###sec10.4.14"); break;
    case CLIENT_ERROR_REQUEST_URI_TOO_LONG: status(stat, "Request URI Too Long", "The server is refusing to service the request becausethe request URI is longer than the server is willing to interpret", "##BASE_HTTP###sec10.4.15"); break;
    case CLIENT_ERROR_UNSUPPORTED_MEDIA_TYPE: status(stat, "Unsupported Media Type", "The server is refusing to service the request becausethe entity of the request is in a format not supported by the requested resource for the requested method", "##BASE_HTTP###sec10.4.16"); break;
    case CLIENT_ERROR_REQUESTED_RANGE_NOT_SATISFIABLE: status(stat, "Requested Range Not Satisfiable", "For byte ranges, this means that the first byte position were greater than the current length of the selected resource", "##BASE_HTTP###sec10.4.17"); break;
    case CLIENT_ERROR_EXPECTATION_FAILED: status(stat, "Expectation Failed", "The expectation given in the request header could notbe met by this server", "##BASE_HTTP###sec10.4.18"); break;
    case CLIENT_ERROR_UNPROCESSABLE_ENTITY: status(stat, "Unprocessable Entity", "The server understands the content type of the request entity and the syntax of the request entity is correct but was unable to process the contained instructions", "##BASE_WEBDAV###STATUS_422"); break;
    case CLIENT_ERROR_LOCKED: status(stat, "Locked", "The source or destination resource of a method is locked", "##BASE_WEBDAV###STATUS_423"); break;
    case CLIENT_ERROR_FAILED_DEPENDENCY: status(stat, "Failed Dependency", "The method could not be performed on the resource because the requested action depended on another action and that action failed", "##BASE_WEBDAV###STATUS_424"); break;
    case SERVER_ERROR_INTERNAL: status(stat, "Internal Server Error", "The server encountered an unexpected condition which prevented it from fulfilling the request", "##BASE_HTTP###sec10.5.1"); break;
    case SERVER_ERROR_NOT_IMPLEMENTED: status(stat, "Not Implemented", "The server does not support the functionality required to fulfill the request", "##BASE_HTTP###sec10.5.2"); break;
    case SERVER_ERROR_BAD_GATEWAY: status(stat, "Bad Gateway", "The server, while acting as a gateway or proxy, received an invalid response from the upstream server it accessed in attempting to fulfill the request", "##BASE_HTTP###sec10.5.3"); break;
    case SERVER_ERROR_SERVICE_UNAVAILABLE: status(stat, "Service Unavailable", "The server is currently unable to handle the request due to a temporary overloading or maintenance of the server", "##BASE_HTTP###sec10.5.4"); break;
    case SERVER_ERROR_GATEWAY_TIMEOUT: status(stat, "Gateway Timeout", "The server, while acting as a gateway or proxy, did not receive a timely response from the upstream server specified by the URI (e.g.HTTP, FTP, LDAP) or some other auxiliary server (e.g. DNS) it needed to access in attempting to complete the request", "##BASE_HTTP###sec10.5.5"); break;
    case SERVER_ERROR_VERSION_NOT_SUPPORTED: status(stat, "Version Not Supported", "The server does not support, or refuses to support, the protocol version that was used in the request message", "##BASE_HTTP###sec10.5.6"); break;
    case SERVER_ERROR_INSUFFICIENT_STORAGE: status(stat, "Insufficient Storage", "The method could not be performed on the resource because the server is unable to store the representation needed to successfully complete the request", "##BASE_WEBDAV###STATUS_507"); break;
    case CONNECTOR_ERROR_CONNECTION: status(stat, "Connection Error", "The connector failed to connect to the server", "##BASE_RESTLET##org/restlet/data/Status.html#CONNECTOR_ERROR_CONNECTION"); break;
    case CONNECTOR_ERROR_COMMUNICATION: status(stat, "Communication Error", "The connector failed to complete the communication with the server", "##BASE_RESTLET##org/restlet/data/Status.html#CONNECTOR_ERROR_COMMUNICATION"); break;
    case CONNECTOR_ERROR_INTERNAL: status(stat, "Internal Connector Error", "The connector encountered an unexpected condition which prevented it from fulfilling the request", "##BASE_RESTLET##org/restlet/data/Status.html#CONNECTOR_ERROR_INTERNAL"); break;
    default:
         std::ostringstream o;
         o << stat;
         status(stat, o.str(), "Status");
    }
}

status::status(int c, const std::string& name, const std::string& description, const std::string& uri) : metadata(name, description), m_code(c), m_uri(uri) {}

const int status::code() const
{
    return m_code;
}
status::operator const int() const
{
    return m_code;
}

const std::string& status::uri() const
{
    return m_uri;
}

}
}
}

