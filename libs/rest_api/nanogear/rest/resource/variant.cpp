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



#include "variant.hpp"

namespace nanogear {
namespace rest {
namespace resource {

const long variant::UNKNOWN_SIZE = -11;

variant::variant(const data::media_type& type) : m_media_type(type) {}

const data::character_set& variant::character_set() const
{
    return m_character_set;
}

const std::list<data::encoding>& variant::encodings() const
{
    return m_encodings;
}

const boost::gregorian::date& variant::expiration_date() const
{
    return m_expiration_date;
}

const std::list<data::language>& variant::languages() const
{
    return m_languages;
}

const data::media_type& variant::media_type() const
{
    return m_media_type;
}

const boost::gregorian::date& variant::modification_date() const
{
    return m_modification_date;
}

const long variant::size() const
{
    return m_size;
}

const data::tag& variant::tag() const
{
    return m_tag;
}

const data::reference& variant::identifier() const
{
    return m_identifier;
}

void variant::set_character_set(const data::character_set& set)
{
    m_character_set = set;
}

void variant::set_expiration_date(const boost::gregorian::date& d)
{
    m_expiration_date = d;
}

void variant::set_media_type(const data::media_type& type)
{
    m_media_type = type;
}

void variant::set_modification_date(const boost::gregorian::date& d)
{
    m_modification_date = d;
}

void variant::set_size(const long size)
{
    m_size = size;
}

void variant::set_tag(const data::tag& t)
{
    m_tag = t;
}

void variant::set_identifier(const data::reference& ident)
{
    m_identifier = ident;
}

}
}
}
