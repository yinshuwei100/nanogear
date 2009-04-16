/*
 * Nanogear - C++ web development framework
 *
 * This library is based on Restlet (R) <http://www.restlet.org> by Noelios Technologies
 * Copyright (C) 2005-2008 by Noelios Technologies <http://www.noelios.com>
 * Restlet is a registered trademark of Noelios Technologies. All other marks and
 * trademarks are property of their respective owners.
 *
 * Copyright (C) 2008-2009 Lorenzo Villani.
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

#include "Directory.h"

#include <QDebug>
#include <QFile>
#include <QFileInfo>

#include "../Request.h"

namespace Nanogear {
namespace Resource {

Directory::Directory(const QString& root) : m_root(root), m_indexAllowed(true) {
    m_mimeMappings["rpm"] = "application/x-rpm";
    m_mimeMappings["pdf"] = "application/pdf";
    m_mimeMappings["sig"] = "application/pgp-signature";
    m_mimeMappings["spl"] = "application/futuresplash";
    m_mimeMappings["class"] = "application/octet-stream";
    m_mimeMappings["ps"] = "application/postscript";
    m_mimeMappings["torrent"] = "application/x-bittorrent";
    m_mimeMappings["dvi"] = "application/x-dvi";
    m_mimeMappings["gz"] = "application/x-gzip";
    m_mimeMappings["pac"] = "application/x-ns-proxy-autoconfig";
    m_mimeMappings["swf"] = "application/x-shockwave-flash";
    m_mimeMappings["tar.gz"] = "application/x-tgz";
    m_mimeMappings["tgz"] = "application/x-tgz";
    m_mimeMappings["tar"] = "application/x-tar";
    m_mimeMappings["zip"] = "application/zip";
    m_mimeMappings["mp3"] = "audio/mpeg";
    m_mimeMappings["m3u"] = "audio/x-mpegurl";
    m_mimeMappings["wma"] = "audio/x-ms-wma";
    m_mimeMappings["wax"] = "audio/x-ms-wax";
    m_mimeMappings["ogg"] = "application/ogg";
    m_mimeMappings["wav"] = "audio/x-wav";
    m_mimeMappings["gif"] = "image/gif";
    m_mimeMappings["jar"] = "application/x-java-archive";
    m_mimeMappings["jpg"] = "image/jpeg";
    m_mimeMappings["jpeg"] = "image/jpeg";
    m_mimeMappings["png"] = "image/png";
    m_mimeMappings["xbm"] = "image/x-xbitmap";
    m_mimeMappings["xpm"] = "image/x-xpixmap";
    m_mimeMappings["xwd"] = "image/x-xwindowdump";
    m_mimeMappings["css"] = "text/css";
    m_mimeMappings["html"] = "text/html";
    m_mimeMappings["htm"] = "text/html";
    m_mimeMappings["js"] = "text/javascript";
    m_mimeMappings["asc"] = "text/plain";
    m_mimeMappings["c"] = "text/plain";
    m_mimeMappings["cpp"] = "text/plain";
    m_mimeMappings["log"] = "text/plain";
    m_mimeMappings["conf"] = "text/plain";
    m_mimeMappings["text"] = "text/plain";
    m_mimeMappings["txt"] = "text/plain";
    m_mimeMappings["dtd"] = "text/xml";
    m_mimeMappings["xml"] = "text/xml";
    m_mimeMappings["mpeg"] = "video/mpeg";
    m_mimeMappings["mpg"] = "video/mpeg";
    m_mimeMappings["mov"] = "video/quicktime";
    m_mimeMappings["qt"] = "video/quicktime";
    m_mimeMappings["avi"] = "video/x-msvideo";
    m_mimeMappings["asf"] = "video/x-ms-asf";
    m_mimeMappings["asx"] = "video/x-ms-asf";
    m_mimeMappings["wmv"] = "video/x-ms-wmv";
    m_mimeMappings["bz2"] = "application/x-bzip";
    m_mimeMappings["tbz"] = "application/x-bzip-compressed-tar";
    m_mimeMappings["tar.bz2"] = "application/x-bzip-compressed-tar";

    m_notAllowed.setData("<html><head><title>403 Forbidden</title></head><body>"
"<h1>Forbidden</h1>"
"<p>Unable to display this resource</p>"
"</body>", "text/html");

    m_xhtmlRepr = "<?xml version=\"1.0\" encoding=\"utf-8\"?>"
"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" \"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">"
"<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"en\">"
"<head>"
"<title>Index of %1</title>"
"<style type=\"text/css\">"
"a, a:active {text-decoration: none; color: blue;}"
"a:visited {color: #48468F;}"
"a:hover, a:focus {text-decoration: underline; color: red;}"
"body {background-color: #F5F5F5;}"
"h2 {margin-bottom: 12px;}"
"table {margin-left: 12px;}"
"th, td { font: 90% monospace; text-align: left;}"
"th { font-weight: bold; padding-right: 14px; padding-bottom: 3px;}"
"td {padding-right: 14px;}"
"td.s, th.s {text-align: right;}"
"div.list { background-color: white; border-top: 1px solid #646464; border-bottom: 1px solid #646464; padding-top: 10px; padding-bottom: 14px;}"
"div.foot { font: 90% monospace; color: #787878; padding-top: 4px;}"
"</style>"
"</head>"
"<body>"
"<h2>Index of %1</h2>"
"<div class=\"list\">"
"<table summary=\"Directory Listing\" cellpadding=\"0\" cellspacing=\"0\">"
"<thead><tr><th class=\"n\">Name</th><th class=\"m\">Last Modified</th><th class=\"s\">Size</th><th class=\"t\">Type</th></tr></thead>"
"<tbody>"
"%2"
"</tbody>"
"</table>"
"</div>"
"<div class=\"foot\">Nanogear</div>"
"</body>"
"</html>";
}


void Directory::handleGet(const Nanogear::Request& request, Nanogear::Response& response) {
    QFileInfo pathInfo(m_root.absolutePath() + request.resourceRef());

    if (pathInfo.exists()) {
        if (pathInfo.isDir()) {
            if (m_indexAllowed) {
                // Return a representation of this directory
                
                QString htmlTableEntries;
                foreach (const QFileInfo& dirFileInfo, QDir(pathInfo.absoluteFilePath()).entryInfoList()) {
                    QString fileType("File");
                    QString dirIdentifier("");
                    QString size(QString::number(dirFileInfo.size()));
                    if (dirFileInfo.isDir()) {
                        fileType = "Directory";
                        dirIdentifier = "/";
                        size = "-";
                    }
                    
                    htmlTableEntries += QString("<tr><td class=\"n\"><a href=\"%1\">%2</a>%3</td><td class=\"m\">%4</td><td class=\"s\">%5</td><td class=\"t\">%6</td></tr>\n")
                        .arg(pathInfo.fileName() + "/" + dirFileInfo.fileName())
                        .arg(dirFileInfo.fileName()).arg(dirIdentifier)
                        .arg(dirFileInfo.lastModified().toString()).arg(size)
                        .arg(fileType);
                }

                m_directoryIndex.setXhtml(m_xhtmlRepr.arg(pathInfo.fileName()).arg(htmlTableEntries));
                
                response.setStatus(Status::OK);
                response.setRepresentation(&m_directoryIndex);
            } else {
                response.setStatus(Status::Forbidden);
                response.setRepresentation(&m_notAllowed);
            }
        } else {
            // Send a file back to the client
            QString mimeType("application/octet-stream");
            if (!m_mimeMappings.value(pathInfo.completeSuffix()).isEmpty())
                mimeType = m_mimeMappings.value(pathInfo.completeSuffix());

            // FIXME: Awful
            QFile file(pathInfo.absoluteFilePath());
            file.open(QIODevice::ReadOnly);
            m_rawFile.setData(mimeType, file.readAll());
            file.close();
            
            response.setStatus(Status::OK);
            response.setRepresentation(&m_rawFile);
        }
    }
}


}
}
