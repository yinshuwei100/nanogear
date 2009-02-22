#ifndef NANOGEAR_REPRESENTATION_H
#define NANOGEAR_REPRESENTATION_H

class QByteArray;

class Representation {
public:
    virtual QByteArray& asByteArray() = 0;
};

#endif /* NANOGEAR_REPRESENTATION_H */
