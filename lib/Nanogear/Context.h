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

#ifndef NANOGEAR_CONTEXT_H
#define NANOGEAR_CONTEXT_H

#include <QMetaType>

class QString;

namespace Nanogear {

/*!
 * \class Context
 * \brief Contextual data provided to a Resource
 *
 * The context is the means by which a Resource may access the environment
 * within the framework.
 */
class Context {
public:
    /*!
     * Default constructor taking no arguments
     */
    Context();

    /*!
     * A constructor used to initialize the path
     * \param path A reference to a QString representing a path
     */
    Context(const QString& path);

    /*!
     * An overloaded constructor provided for convenience
     * \param path A C-style string representing a path
     */
    Context(const char* charPath);

    virtual ~Context();

    /*!
     * Set the path assigned to this context
     * \param path
     */
    void setPath(const QString& path);

    const QString& path() const;
private:
    struct Private;
    Private* d;
};

bool operator==(const Context&, const Context&);
bool operator!=(const Context&, const Context&);

}

Q_DECLARE_METATYPE(Nanogear::Context)

#endif /* NANOGEAR_CONTEXT_H */
