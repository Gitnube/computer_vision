#include "imagenormalizer.h"

ImageNormalizer::ImageNormalizer()
{

}

double * ImageNormalizer::normalize(double *data, int size, double upperLimit)
{
    double min, max;
    min = max = 0;
    for(int i = 0; i < size; i++)
    {
        if(min > data[i])
            min = data[i];
        else if(max < data[i])
            max = data[i];
    }
    double *res_bits = new double[size];
    for(int i = 0; i < size; i++)
        res_bits[i] = (data[i] - min) * upperLimit / (max - min);
    return res_bits;
}

double * ImageNormalizer::normalize(uchar *data, int size, double upperLimit)
{
    return normalize(toDouble(data, size), size, upperLimit);
}

uchar * ImageNormalizer::toUchar(double * data, int size)
{
    uchar *res_bits = new uchar[size];
    for(int i = 0; i < size; i++)
        res_bits[i] = data[i];
    return res_bits;
}

double * ImageNormalizer::toDouble(uchar * data, int size)
{
    double *res_bits = new double[size];
    for(int i = 0; i < size; i++)
        res_bits[i] = data[i];
    return res_bits;
}
