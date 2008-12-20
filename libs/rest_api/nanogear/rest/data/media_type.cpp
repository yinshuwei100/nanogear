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

#include "media_type.hpp"

namespace nanogear {
namespace rest {
namespace data {

#define add_media_type(x, y, z) media_type media_type::x(y, z)
add_media_type(all, "*/*", "All media");
add_media_type(application::all, "application/*", "All application documents");
add_media_type(application::atom, "application/atom+xml", "Atom syndication documents");
add_media_type(application::cab, "application/vnd.ms-cab-compressed", "Microsoft Cabinet archive");
add_media_type(application::excel, "application/vnd.ms-excel", "Microsoft Excel document");
add_media_type(application::flash, "application/x-shockwave-flash", "Shockwave Flash object");
add_media_type(application::gnu_tar, "application/x-gtar", "GNU Tar archive");
add_media_type(application::gnu_zip, "application/x-gzip", "GNU Zip archive");
add_media_type(application::http_cookies, "application/x-http-cookies", "HTTP cookies");
add_media_type(application::java_archive, "application/x-java-archive", "Java Archive");
add_media_type(application::java_object, "application/x-java-object", "Java Object");
add_media_type(application::javascript, "application/x-javascript", "Javascript document");
add_media_type(application::json, "application/json", "JavaScript Object Notation document");
add_media_type(application::octet_stream, "application/octet-stream", "Raw octet stream");
add_media_type(application::pdf, "application/pdf", "Adobe PDF document");
add_media_type(application::postscript, "application/postscript", "Postscript document");
add_media_type(application::powerpoint, "application/vnd.ms-powerpoint", "Microsoft Powerpoint document");
add_media_type(application::project, "application/vnd.ms-project", "Microsoft Project document");
add_media_type(application::rdf_xml, "application/rdf+xml",
               "XML serialized Resource Description Framework document");
add_media_type(application::rtf, "application/rtf", "Rich Text Format document");
add_media_type(application::stuffit, "application/x-stuffit", "Stuffit archive");
add_media_type(application::tar, "application/x-tar", "Tape ARchive");
add_media_type(application::word, "application/msword", "Microsoft Word Document");
add_media_type(application::www_form, "application/x-www-form-urlencoded",
               "Web form (URL encoded)");
add_media_type(application::xhtml, "application/xhtml+xml", "XHTML document");
add_media_type(application::xml, "application/xml", "XML document");
add_media_type(application::zip, "application/zip", "Zip document");
add_media_type(audio::all, "audio/*", "All audios");
add_media_type(audio::mp3, "audio/mpeg", "MPEG Audio (MP3)");
add_media_type(audio::real, "application/x-pn-realaudio", "Real audio");
add_media_type(audio::wav, "application/x-wav", "Waveform audio");
add_media_type(image::all, "image/*", "All images");
add_media_type(image::bmp, "image/bmp", "Windows Bitmap");
add_media_type(image::gif, "image/gif", "GIF Image");
add_media_type(image::icon, "image/x-icon", "Windows Icon (Favicon)");
add_media_type(image::jpeg, "image/jpeg", "JPEG Image");
add_media_type(image::png, "image/png", "Portable Network Graphics");
add_media_type(image::svg, "image/svg+xml", "Scalable Vector Graphics");
add_media_type(message::all, "message/*", "All messages");
add_media_type(model::all, "model/*", "All models");
add_media_type(multipart::all, "multipart/*", "All multipart data");
add_media_type(multipart::form_data, "multipart/form-data", "Multipart form data");
add_media_type(text::all, "text/*", "All text");
add_media_type(text::icalendar, "text/calendar", "iCalendar event");
add_media_type(text::css, "text/css", "Cascading Style Sheet");
add_media_type(text::html, "text/html", "HyperText Markup Language document");
add_media_type(text::plain, "text/plain", "Plain text document");
add_media_type(text::rdf_n3, "text/rdf+n3",
               "N3 serialized Resource Description Framework document");
add_media_type(text::uri_list, "text/uri-list", "List of URIs");
add_media_type(text::vcard, "text/x-vcard", "vCard");
add_media_type(text::xml, "text/xml", "XML text document");
add_media_type(video::all, "video/*", "All videos");
add_media_type(video::avi, "video/x-msvideo", "AVI video");
add_media_type(video::mpeg, "video/mpeg", "MPEG video");
add_media_type(video::quicktime, "video/quicktime", "Quicktime video");
add_media_type(video::wmv, "video/x-ms-wmv", "Windows Media video");
#undef add_media_type

media_type& media_type::value_of(const std::string& name) {
    #define media_type_case(x) if (name == x.name()) return x
    media_type_case(all);
    media_type_case(application::all);
    media_type_case(application::atom);
    media_type_case(application::cab);
    media_type_case(application::excel);
    media_type_case(application::flash);
    media_type_case(application::gnu_tar);
    media_type_case(application::gnu_zip);
    media_type_case(application::http_cookies);
    media_type_case(application::java_archive);
    media_type_case(application::java_object);
    media_type_case(application::javascript);
    media_type_case(application::json);
    media_type_case(application::octet_stream);
    media_type_case(application::pdf);
    media_type_case(application::postscript);
    media_type_case(application::project);
    media_type_case(application::rdf_xml);
    media_type_case(application::rtf);
    media_type_case(application::stuffit);
    media_type_case(application::tar);
    media_type_case(application::word);
    media_type_case(application::www_form);
    media_type_case(application::xhtml);
    media_type_case(application::xml);
    media_type_case(application::zip);
    media_type_case(audio::all);
    media_type_case(audio::mp3);
    media_type_case(audio::real);
    media_type_case(audio::wav);
    media_type_case(image::all);
    media_type_case(image::bmp);
    media_type_case(image::gif);
    media_type_case(image::icon);
    media_type_case(image::jpeg);
    media_type_case(image::png);
    media_type_case(image::svg);
    media_type_case(message::all);
    media_type_case(model::all);
    media_type_case(multipart::all);
    media_type_case(multipart::form_data);
    media_type_case(text::all);
    media_type_case(text::icalendar);
    media_type_case(text::css);
    media_type_case(text::html);
    media_type_case(text::plain);
    media_type_case(text::rdf_n3);
    media_type_case(text::uri_list);
    media_type_case(text::vcard);
    media_type_case(text::xml);
    media_type_case(video::all);
    media_type_case(video::avi);
    media_type_case(video::mpeg);
    media_type_case(video::quicktime);
    media_type_case(video::wmv);
    #undef media_type_case
    return all;
}

}
}
}
