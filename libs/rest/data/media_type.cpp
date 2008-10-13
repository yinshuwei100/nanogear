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

media_type media_type::all("*/*", "All media");

media_type media_type::application_all("application/*",
                                       "All application documents");

media_type media_type::atom("application/atom+xml",
                            "Atom syndication documents");

media_type media_type::cab("application/vnd.ms-cab-compressed",
                           "Microsoft Cabinet archive");

media_type media_type::excel("application/vnd.ms-excel",
                             "Microsoft Excel document");

media_type media_type::flash("application/x-shockwave-flash",
                             "Shockwave Flash object");

media_type media_type::gnu_tar("application/x-gtar",
                               "GNU Tar archive");

media_type media_type::gnu_zip("application/x-gzip",
                               "GNU Zip archive");

media_type media_type::http_cookies("application/x-http-cookies",
                                    "HTTP cookies");

media_type media_type::java_archive("application/x-java-archive",
                                    "Java Archive");

media_type media_type::java_object("application/x-java-object",
                                   "Java Object");

media_type media_type::javascript("application/x-javascript",
                                   "Javascript document");

media_type media_type::json("application/json",
                            "JavaScript Object Notation document");

media_type media_type::octet_stream("application/octet-stream",
                                    "Raw octet stream");

media_type media_type::pdf("application/pdf",
                           "Adobe PDF document");

media_type media_type::postscript("application/postscript",
                                  "Postscript document");

media_type media_type::powerpoint("application/vnd.ms-powerpoint",
                                  "Microsoft Powerpoint document");

media_type media_type::project("application/vnd.ms-project",
                               "Microsoft Project document");

media_type media_type::rdf_xml("application/rdf+xml",
                            "XML serialized Resource Description Framework document");

media_type media_type::rtf("application/rtf",
                           "Rich Text Format document");

media_type media_type::stuffit("application/x-stuffit",
                               "Stuffit archive");

media_type media_type::tar("application/x-tar",
                           "Tape ARchive");

media_type media_type::word("application/msword",
                            "Microsoft Word Document");

media_type media_type::www_form("application/x-www-form-urlencoded",
                                "Web form (URL encoded)");

media_type media_type::www_form("application/x-www-form-urlencoded",
                                "Web form (URL encoded)");

media_type media_type::xhtml("application/xhtml+xml",
                             "XHTML document");

media_type media_type::xml("application/xml",
                           "XML document");

media_type media_type::zip("application/zip",
                           "Zip document");

media_type media_type::audio_all("audio/*",
                                 "All audios");

media_type media_type::mp3("application/mpeg",
                           "MPEG Audio (MP3)");

media_type media_type::real_audio("application/x-pn-realaudio",
                                  "Real audio");

media_type media_type::wav("application/x-wav",
                           "Waveform audio");

media_type media_type::image_all("image/*",
                                 "All images");

media_type media_type::bmp("application/bmp",
                           "Windows Bitmap");

media_type media_type::gif("application/gif",
                           "GIF Image");

media_type media_type::icon("application/x-icon",
                            "Windows Icon (Favicon)");

media_type media_type::jpeg("application/jpeg",
                            "JPEG Image");

media_type media_type::png("application/png",
                           "Portable Network Graphics");

media_type media_type::svg("application/svg+xml",
                           "Scalable Vector Graphics");

media_type media_type::message_all("message/*",
                                   "All messages");

media_type media_type::model_all("model/*",
                                 "All models");

media_type media_type::multipart_all("multipart/*",
                                     "All multipart data");

media_type media_type::forum_data("multipart/form-data",
                                  "Multipart form data");

media_type media_type::text_all("text/*",
                                "All texts");

media_type media_type::icalendar("text/calendar",
                                 "iCalendar event");

media_type media_type::css("text/css",
                           "Cascading Style Sheet");

media_type media_type::html("text/html",
                            "HyperText Markup Language document");

media_type media_type::plain("text/plain",
                             "Plain text document");

media_type media_type::rdf_n3("text/rdf+n3",
                              "N3 serialized Resource Description Framework document");

media_type media_type::uri_list("text/uri-list",
                                "List of URIs");

media_type media_type::vcard("text/x-vcard",
                             "vCard");

media_type media_type::xml_text("text/xml",
                                "XML text document");

media_type media_type::video_all("video/*",
                                "All videos");

media_type media_type::avi("video/x-msvideo",
                           "AVI video");

media_type media_type::mpeg("video/mpeg",
                           "MPEG video");

media_type media_type::quicktime("video/quicktime",
                                 "Quicktime video");

media_type media_type::wmv("video/x-ms-wmv",
                           "Windows Media video");

media_type& media_type::value_of(const std::string& name) {
    if (name == all.name()) return all;
    if (name == application_all.name()) return application_all;
    if (name == atom.name()) return atom;
    if (name == cab.name()) return cab;
    if (name == excel.name()) return excel;
    if (name == flash.name()) return flash;
    if (name == gnu_tar.name()) return gnu_tar;
    if (name == gnu_zip.name()) return gnu_zip;
    if (name == http_cookies.name()) return http_cookies;
    if (name == java_archive.name()) return java_archive;
    if (name == java_object.name()) return java_object;
    if (name == javascript.name()) return javascript;
    if (name == json.name()) return json;
    if (name == pdf.name()) return pdf;
    if (name == postscript.name()) return postscript;
    if (name == project.name()) return project;
    if (name == rdf_xml.name()) return rdf_xml;
    if (name == rtf.name()) return rtf;
    if (name == stuffit.name()) return stuffit;
    if (name == tar.name()) return tar;
    if (name == word.name()) return word;
    if (name == www_form.name()) return www_form;
    if (name == xhtml.name()) return xhtml;
    if (name == xml.name()) return xml;
    if (name == zip.name()) return zip;
    if (name == audio_all.name()) return audio_all;
    if (name == mp3.name()) return mp3;
    if (name == real_audio.name()) return real_audio;
    if (name == wav.name()) return wav;
    if (name == image_all.name()) return image_all;
    if (name == bmp.name()) return bmp;
    if (name == gif.name()) return gif;
    if (name == icon.name()) return icon;
    if (name == jpeg.name()) return jpeg;
    if (name == png.name()) return png;
    if (name == svg.name()) return svg;
    if (name == message_all.name()) return message_all;
    if (name == model_all.name()) return model_all;
    if (name == multipart_all.name()) return multipart_all;
    if (name == form_data.name()) return form_data;
    if (name == text_all.name()) return text_all;
    if (name == icalendar.name()) return icalendar;
    if (name == css.name()) return css;
    if (name == html.name()) return html;
    if (name == plain.name()) return plain;
    if (name == rdf_n3.name()) return rdf_n3;
    if (name == uri_list.name()) return uri_list;
    if (name == vcard.name()) return vcard;
    if (name == xml_text.name()) return xml_text;
    if (name == video_all.name()) return video_all;
    if (name == avi.name()) return avi;
    if (name == mpeg.name()) return mpeg;
    if (name == quicktime.name()) return quicktime;
    if (name == wmv.name()) return wmv;
    return all;
}

}
}
}
