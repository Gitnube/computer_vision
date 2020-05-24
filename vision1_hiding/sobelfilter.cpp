#include "sobelfilter.h"
#include "simplefilter.h"
#include "dxcoregenerator.h"
#include "dycoregenerator.h"
#include "math.h"
#include "imagenormalizer.h"

SobelFilter::SobelFilter()
{

}

QImage *SobelFilter::process(IImageExpander *expander, QImage *img)
{
    ImageNormalizer *normalizer = new ImageNormalizer();
    IImageFilter *dxFilter = new SimpleFilter(new DXCoreGenerator());
    QImage *dxImage = dxFilter->process(expander, img);
    IImageFilter *dyFilter = new SimpleFilter(new DYCoreGenerator());
    QImage *dyImage = dyFilter->process(expander, img);
    int size = img->sizeInBytes();
    double *gradData = new double [size];
    const uchar *dxData = dxImage->constBits();
    const uchar *dyData = dyImage->constBits();
    int bytesCount = img->sizeInBytes();
    for(int i = 0; i < bytesCount; i++)
        gradData[i] = sqrt(dxData[i] * dxData[i] + dyData[i] * dyData[i]);
    gradData = normalizer->normalize(gradData, size, 255);
    return new QImage(normalizer->toUchar(gradData, size), img->width(), img->height(), img->format());
}
