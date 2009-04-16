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

#ifndef NANOGEAR_RESOURCE_DIRECTORY_H
#define NANOGEAR_RESOURCE_DIRECTORY_H

#include <QDir>

#include "Resource.h"

namespace Nanogear {
namespace Resource {

class Directory : public Resource {
public:
    Directory(const QString& root);
    
    virtual void handleGet(const Request& request, Response& response);

    /*!
     * Set the root directory on the filesystem
     * \param root An absolute or relative path to a directory on the filesystem
     */
    void setRoot(const QString& root)
        { m_root = QDir(root); }

    /*!
     * \return The absolute path to the root directory
     */
    QString root() const
        { return m_root.absolutePath(); }

    /*!
     * Set this to true to display a directory index when no index file is
     * found. If false, this Resource will answer with Status::Forbidden
     * \param indexAllowed Whether or not allow directory index generation
     */
    void setIndexAllowed(bool indexAllowed)
        { m_indexAllowed = indexAllowed; }

    /*!
     * \return True if directory index generation is allowed
     */
    bool isIndexAllowed() const
        { return m_indexAllowed; }

    /*!
     * \return a modifiable QHash mapping file extensions to MIME types
     */
    QHash<QString, QString>& mimeMappings()
        { return m_mimeMappings; }
private:
    QDir m_root;
    bool m_indexAllowed;
    QString m_indexName;
    QString m_xhtmlRepr;
    QHash<QString, QString> m_mimeMappings;
    
    Nanogear::Resource::Representation m_notAllowed;
    Nanogear::Resource::Representation m_directoryIndex;
    Nanogear::Resource::Representation m_rawFile;
};

}
}
#endif // NANOGEAR_RESOURCE_DIRECTORY_H
