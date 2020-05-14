#ifndef IMAGEFILTER_H
#define IMAGEFILTER_H

#include "QImage"
#include "icoregenerator.h"
#include "iimageexpander.h"
#include "iimagefilter.h"

class SimpleFilter : public IImageFilter
{
public:
    SimpleFilter(ICoreGenerator *generator, int size = 3);
    QImage *process(IImageExpander *expander, QImage *img) override;
private:
    QImage *convolution(QImage *input);
    double ** generateCore();
    int size;
    double **core;
    ICoreGenerator *generator;
    IImageExpander *expander;
};

#endif // IMAGEFILTER_H
