#ifndef IIMAGEEXPANDER_H
#define IIMAGEEXPANDER_H

#include "QImage"

class IImageExpander
{
public:
    virtual QImage * expand(QImage *original, int expand) = 0;
};

#endif // IIMAGEEXPANDER_H
