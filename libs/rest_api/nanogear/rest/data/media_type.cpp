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
add_media_type(application_all, "application/*", "All application documents");
add_media_type(atom, "application/atom+xml", "Atom syndication documents");
add_media_type(cab, "application/vnd.ms-cab-compressed", "Microsoft Cabinet archive");
add_media_type(excel, "application/vnd.ms-excel", "Microsoft Excel document");
add_media_type(flash, "application/x-shockwave-flash", "Shockwave Flash object");
add_media_type(gnu_tar, "application/x-gtar", "GNU Tar archive");
add_media_type(gnu_zip, "application/x-gzip", "GNU Zip archive");
add_media_type(http_cookies, "application/x-http-cookies", "HTTP cookies");
add_media_type(java_archive, "application/x-java-archive", "Java Archive");
add_media_type(java_object, "application/x-java-object", "Java Object");
add_media_type(javascript, "application/x-javascript", "Javascript document");
add_media_type(json, "application/json", "JavaScript Object Notation document");
add_media_type(octet_stream, "application/octet-stream", "Raw octet stream");
add_media_type(pdf, "application/pdf", "Adobe PDF document");
add_media_type(postscript, "application/postscript", "Postscript document");
add_media_type(powerpoint, "application/vnd.ms-powerpoint", "Microsoft Powerpoint document");
add_media_type(project, "application/vnd.ms-project", "Microsoft Project document");
add_media_type(rdf_xml, "application/rdf+xml",
               "XML serialized Resource Description Framework document");
add_media_type(rtf, "application/rtf", "Rich Text Format document");
add_media_type(stuffit, "application/x-stuffit", "Stuffit archive");
add_media_type(tar, "application/x-tar", "Tape ARchive");
add_media_type(word, "application/msword", "Microsoft Word Document");
add_media_type(www_form, "application/x-www-form-urlencoded",
               "Web form (URL encoded)");
add_media_type(xhtml, "application/xhtml+xml", "XHTML document");
add_media_type(xml, "application/xml", "XML document");
add_media_type(zip, "application/zip", "Zip document");
add_media_type(audio_all, "audio/*", "All audios");
add_media_type(mp3, "audio/mpeg", "MPEG Audio (MP3)");
add_media_type(real_audio, "application/x-pn-realaudio", "Real audio");
add_media_type(wav, "application/x-wav", "Waveform audio");
add_media_type(image_all, "image/*", "All images");
add_media_type(bmp, "image/bmp", "Windows Bitmap");
add_media_type(gif, "image/gif", "GIF Image");
add_media_type(icon, "image/x-icon", "Windows Icon (Favicon)");
add_media_type(jpeg, "image/jpeg", "JPEG Image");
add_media_type(png, "image/png", "Portable Network Graphics");
add_media_type(svg, "image/svg+xml", "Scalable Vector Graphics");
add_media_type(message_all, "message/*", "All messages");
add_media_type(model_all, "model/*", "All models");
add_media_type(multipart_all, "multipart/*", "All multipart data");
add_media_type(form_data, "multipart/form-data", "Multipart form data");
add_media_type(text_all, "text/*", "All text");
add_media_type(icalendar, "text/calendar", "iCalendar event");
add_media_type(css, "text/css", "Cascading Style Sheet");
add_media_type(html, "text/html", "HyperText Markup Language document");
add_media_type(plain, "text/plain", "Plain text document");
add_media_type(rdf_n3, "text/rdf+n3",
               "N3 serialized Resource Description Framework document");
add_media_type(uri_list, "text/uri-list", "List of URIs");
add_media_type(vcard, "text/x-vcard", "vCard");
add_media_type(xml_text, "text/xml", "XML text document");
add_media_type(video_all, "video/*", "All videos");
add_media_type(avi, "video/x-msvideo", "AVI video");
add_media_type(mpeg, "video/mpeg", "MPEG video");
add_media_type(quicktime, "video/quicktime", "Quicktime video");
add_media_type(wmv, "video/x-ms-wmv", "Windows Media video");
#undef add_media_type

media_type& media_type::value_of(const std::string& name) {
    #define media_type_case(x) if (name == x.name()) return x
    media_type_case(all);
    media_type_case(application_all);
    media_type_case(atom);
    media_type_case(cab);
    media_type_case(excel);
    media_type_case(flash);
    media_type_case(gnu_tar);
    media_type_case(gnu_zip);
    media_type_case(http_cookies);
    media_type_case(java_archive);
    media_type_case(java_object);
    media_type_case(javascript);
    media_type_case(json);
    media_type_case(pdf);
    media_type_case(postscript);
    media_type_case(project);
    media_type_case(rdf_xml);
    media_type_case(rtf);
    media_type_case(stuffit);
    media_type_case(tar);
    media_type_case(word);
    media_type_case(www_form);
    media_type_case(xhtml);
    media_type_case(xml);
    media_type_case(zip);
    media_type_case(audio_all);
    media_type_case(mp3);
    media_type_case(real_audio);
    media_type_case(wav);
    media_type_case(image_all);
    media_type_case(bmp);
    media_type_case(gif);
    media_type_case(icon);
    media_type_case(jpeg);
    media_type_case(png);
    media_type_case(svg);
    media_type_case(message_all);
    media_type_case(model_all);
    media_type_case(multipart_all);
    media_type_case(form_data);
    media_type_case(text_all);
    media_type_case(icalendar);
    media_type_case(css);
    media_type_case(html);
    media_type_case(plain);
    media_type_case(rdf_n3);
    media_type_case(uri_list);
    media_type_case(vcard);
    media_type_case(xml_text);
    media_type_case(video_all);
    media_type_case(avi);
    media_type_case(mpeg);
    media_type_case(quicktime);
    media_type_case(wmv);
    #undef media_type_case
    return all;
}

}
}
}
