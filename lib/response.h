/*- HEADER NAME: Response -*/

#ifndef NANOGEAR_RESPONSE_H
#define NANOGEAR_RESPONSE_H

#include "representation.h"

class Response {
public:
    void setRepresentation(const Representation& representation)
        { m_representation = representation; }
    const Representation& representation() const
        { return m_representation; }
private:
    Representation m_representation;
};

#endif /* NANOGEAR_RESPONSE_H */
