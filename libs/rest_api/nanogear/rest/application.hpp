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



#ifndef NANOGEAR_REST_APPLICATION_HPP
#define NANOGEAR_REST_APPLICATION_HPP

#include <boost/shared_ptr.hpp>

#include "controller.hpp"
#include "data/response.hpp"

#include <string>

namespace nanogear {
namespace rest {

class application : public controller {
public:
    application();
    application(const context&);
    ~application();

    virtual controller::ptr& create_root();
    const controller::ptr& root() const;
    
    void operator()(const data::request&, const data::response&);
    
    void start();
    void stop();

    // Getters and setters
    void set_description(const std::string& value);
    const std::string& description() const;

    void set_author(const std::string& value);
    const std::string& author() const;

    void set_name(const std::string& value);
    const std::string& name() const;

    void set_owner(const std::string& value);
    const std::string& owner() const;

//    void set_connector(const service::connector& value);
//    service::connector connector() const;

//    void set_converter(const service::converter& value);
//    service::converter converter() const;

//    void set_decoder(const service::decoder& value);
//    service::decoder decoder() const;

//    void set_status(const service::status& value);
//    service::status status() const;

//    void set_tunnel(const service::tunnel& value);
//    service::tunnel tunnel() const;

//    void set_metadata(const service::metadata& value);

    typedef boost::shared_ptr<application> ptr;
    
private:
    std::string m_author;
    std::string m_description;
    std::string m_name;
    std::string m_owner;
    
//    service::connector m_connector;
//    service::converter m_converter;
//    service::decoder m_decoder;
//    service::status m_status;
//    service::tunnel m_tunnel;
//    service::metadata m_metadata;
};

}
}

#endif /* NANOGEAR_REST_APPLICATION_HPP */
