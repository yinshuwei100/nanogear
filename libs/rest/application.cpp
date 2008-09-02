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
 
#include "application.hpp"

namespace nanogear {
namespace rest {

application::application()
{
}

application::application(context c)
{
}


application::~application()
{
}

// Getters and setters follows
std::string application::description() const {
    return m_description;
}
void application::set_description(const std::string& value) {
    m_description = value;
}

std::string application::author() const {
    return m_author;
}
void application::set_author(const std::string& value) {
    m_author = value;
}

std::string application::name() const {
    return m_name;
}
void application::set_name(const std::string& value) {
    m_name = value;
}


std::string application::owner() const {
    return m_owner;
}
void application::set_owner(const std::string& value) {
    m_owner = value;
}

service::connector application::connector() const {
    return m_connector;
}
void application::set_connector(const service::connector& value) {
    m_connector = value;
}


service::converter application::converter() const {
    return m_converter;
}
void application::set_converter(const service::converter& value) {
    m_converter = value;
}


service::decoder application::decoder() const {
    return m_decoder;
}
void application::set_decoder(const service::decoder& value) {
    m_decoder = value;
}


service::status application::status() const {
    return m_status;
}
void application::set_status(const service::status& value) {
    m_status = value;
}


service::tunnel application::tunnel() const {
    return m_tunnel;
}
void application::set_tunnel(const service::tunnel& value) {
    m_tunnel = value;
}


} // end
}
