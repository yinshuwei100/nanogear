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



#ifndef NANOGEAR_REST_RESOURCE_VARIANT_HPP
#define NANOGEAR_REST_RESOURCE_VARIANT_HPP

#include "../data/language.hpp"
#include "../data/media_type.hpp"
#include "../data/character_set.hpp"
#include "../data/encoding.hpp"
#include "../data/tag.hpp"
#include "../data/reference.hpp"

#include <string>
#include <list>
#include <boost/date_time/gregorian/greg_date.hpp>

namespace nanogear {
namespace rest {
namespace resource {

/**
 @author
 */
class variant {
public:
    static const long UNKNOWN_SIZE;

    variant(const data::media_type& type = data::media_type());
    const data::character_set& character_set() const;
    const std::list<data::encoding>& encodings() const;
    const boost::gregorian::date& expiration_date() const;
    const std::list<data::language>& languages() const;
    const data::media_type& media_type() const;
    const boost::gregorian::date& modification_date() const;
    const long size() const;
    const data::tag& tag() const;
    const data::reference& identifier() const;
    void set_character_set(const data::character_set&);
    void set_expiration_date(const boost::gregorian::date&);
    void set_media_type(const data::media_type&);
    void set_modification_date(const boost::gregorian::date&);
    void set_size(const long);
    void set_tag(const data::tag&);
    void set_identifier(const data::reference&);

private:
    std::list<data::language> m_languages;
    data::media_type m_media_type;
    data::character_set m_character_set;
    std::list<data::encoding> m_encodings;
    long m_size;
    boost::gregorian::date m_expiration_date;
    boost::gregorian::date m_modification_date;
    data::tag m_tag;
    data::reference m_identifier;    

};

}
}
}

#endif /* NANOGEAR_REST_RESOURCE_VARIANT_HPP */
