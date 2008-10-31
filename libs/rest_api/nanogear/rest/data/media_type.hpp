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

#ifndef NANOGEAR_REST_DATA_MEDIA_TYPE_HPP
#define NANOGEAR_REST_DATA_MEDIA_TYPE_HPP

#include "metadata.hpp"

#include <string>

namespace nanogear {
namespace rest {
namespace data {

class media_type : public metadata {
public:
    media_type(const std::string& name) : metadata(name) {}
    media_type(const std::string& name, const std::string& description) :
        metadata(name, description) {}
    virtual ~media_type() {};

    static media_type all;
    static media_type application_all;
    static media_type atom;
    static media_type cab;
    static media_type excel;
    static media_type flash;
    static media_type gnu_tar;
    static media_type gnu_zip;
    static media_type http_cookies;
    static media_type java_archive;
    static media_type java_object;
    static media_type javascript;
    static media_type json;
    static media_type octet_stream;
    static media_type pdf;
    static media_type postscript;
    static media_type powerpoint;
    static media_type project;
    static media_type rdf_xml;
    static media_type rtf;
    static media_type stuffit;
    static media_type tar;
    static media_type word;
    static media_type www_form;
    static media_type xhtml;
    static media_type xml;
    static media_type zip;
    static media_type audio_all;
    static media_type mp3;
    static media_type real_audio;
    static media_type wav;
    static media_type image_all;
    static media_type bmp;
    static media_type gif;
    static media_type icon;
    static media_type jpeg;
    static media_type png;
    static media_type svg;
    static media_type message_all;
    static media_type model_all;
    static media_type multipart_all;
    static media_type form_data;
    static media_type text_all;
    static media_type icalendar;
    static media_type css;
    static media_type html;
    static media_type plain;
    static media_type rdf_n3;
    static media_type uri_list;
    static media_type vcard;
    static media_type xml_text;
    static media_type video_all;
    static media_type avi;
    static media_type mpeg;
    static media_type quicktime;
    static media_type wmv;
    static media_type& value_of(const std::string& name);
};


}
}
}

#endif /* NANOGEAR_REST_DATA_MEDIA_TYPE_HPP */
