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

#ifndef NANOGEAR_RESTAPPLICATION_HPP
#define NANOGEAR_RESTAPPLICATION_HPP

namespace std {
    class string;
}

namespace nanogear {
namespace rest {

class application : public restlet {
public:
    application();
    application(context);
    ~application();

    virtual restlet create_root();
    restlet root();
    
    service::connector& connector();
    service::converter& converter();
    service::decoder& decoder();
    service::status& status();
    service::tunnel& tunnel();
    
    void handle(data::request&, data::response&);

    
    // Getters and setters
    void set_description(const std::string& value);
    std::string description() const;

    void set_author(const std::string& value);
    std::string author() const;

    void set_name(const std::string& value);
    std::string name() const;

    void set_owner(const std::string& value);
    std::string owner() const;

    void set_connector(const service::connector& value);
    service::connector connector() const;

    void set_converter(const service::converter& value);
    service::converter converter() const;

    void set_decoder(const service::decoder& value);
    service::decoder decoder() const;

    void set_status(const service::status& value);
    service::status status() const;

    void set_tunnel(const service::tunnel& value);
    service::tunnel tunnel() const;
    
private:
    std::string m_author;
    std::string m_description;
    std::string m_name;
    std::string m_owner;
    
    service::connector m_connector;
    service::converter m_converter;
    service::decoder m_decoder;
    service::status m_status;
    service::tunnel m_tunnel;
};

}
}

#endif
