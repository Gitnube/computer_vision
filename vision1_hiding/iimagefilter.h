#ifndef IIMAGEFILTER_H
#define IIMAGEFILTER_H

#include "QImage"
#include "iimageexpander.h"

class IImageFilter
{
public:
    virtual QImage *process(IImageExpander *expander, QImage *img) = 0;
};

#endif // IIMAGEFILTER_H
