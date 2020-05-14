#ifndef SOBELFILTER_H
#define SOBELFILTER_H

#include "iimageexpander.h"
#include "iimagefilter.h"

class SobelFilter : public IImageFilter
{
public:
    SobelFilter();
    QImage *process(IImageExpander *expander, QImage *img) override;
private:
    IImageExpander *expander;
};

#endif // SOBELFILTER_H
