#ifndef IMAGENORMALIZER_H
#define IMAGENORMALIZER_H

#include <QtGlobal>

class ImageNormalizer
{
public:
    ImageNormalizer();
    double *normalize(double *data, int size, double upperLimit);
    double *normalize(uchar *data, int size, double upperLimit);
    uchar * toUchar(double * data, int size);
    double * toDouble(uchar * data, int size);
};

#endif // IMAGENORMALIZER_H
