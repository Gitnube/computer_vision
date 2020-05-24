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
    QImage *fullConvolution(QImage *input);
    QImage *sepConvolution(QImage *input);
    double * xConvolution(const double *input, int height, int width);
    double * yConvolution(const double *input, int height, int width);
    int size;
    double **core, *coreX, *coreY;
    ICoreGenerator *generator;
    IImageExpander *expander;
};

#endif // IMAGEFILTER_H
