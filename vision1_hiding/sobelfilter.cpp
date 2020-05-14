#include "sobelfilter.h"
#include "simplefilter.h"
#include "dxcoregenerator.h"
#include "dycoregenerator.h"
#include "math.h"

SobelFilter::SobelFilter()
{

}

QImage *SobelFilter::process(IImageExpander *expander, QImage *img)
{
    IImageFilter *dxFilter = new SimpleFilter(new DXCoreGenerator());
    QImage *dxImage = dxFilter->process(expander, img);
    IImageFilter *dyFilter = new SimpleFilter(new DYCoreGenerator());
    QImage *dyImage = dyFilter->process(expander, img);
    QImage *gradImage = new QImage(img->width(), img->height(), img->format());
    uchar *gradData = gradImage->bits();
    const uchar *dxData = dxImage->constBits();
    const uchar *dyData = dyImage->constBits();
    int bytesCount = img->sizeInBytes();
    for(int i = 0; i < bytesCount; i++)
        gradData[i] = sqrt(dxData[i] * dxData[i] + dyData[i] * dyData[i]);
    return gradImage;
}
