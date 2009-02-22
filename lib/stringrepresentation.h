#ifndef NANOGEAR_STRINGREPRESENTATION_H
#define NANOGEAR_STRINGREPRESENTATION_H

#include "representation.h"

#include <QString>

class StringRepresentation : public Representation {
public:
    StringRepresentation(const QString& repr);

    virtual QByteArray& asByteArray()
        { return m_representation; }
private:
    QString m_representation;
};

#endif /* NANOGEAR_STRINGREPRESENTATION_H */
