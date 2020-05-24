#include "simplefilter.h"
#include "imagenormalizer.h"

SimpleFilter::SimpleFilter(ICoreGenerator *generator, int size):
    size(size), generator(generator)
{
    if(generator->isSeparable()) {
        coreX = generator->generateX(size);
        coreY = generator->generateY(size);
        core = nullptr;
    }
    else {
        core = generator->generate(size);
        coreX = coreY = nullptr;
    }
}

QImage *SimpleFilter::process(IImageExpander *expander, QImage *img)
{
    this->expander = expander;
    return convolution(img);
}

QImage *SimpleFilter::convolution(QImage *input)
{
    if(core != nullptr)
        return fullConvolution(input);
    else return sepConvolution(input);
}

double * SimpleFilter::xConvolution(const double *input, int height, int width)
{
    int index, index1, nheight;
    nheight = height + size - 1;
    double *res_intensity = new double [nheight * width];
    index = index1 = 0;
    for(int row = 0; row < nheight; row++)
    {
        index1 += size - 1;
        for(int col = 0; col < width; col++)
        {
            res_intensity[index] = 0;
            for(int rmatr = size - 1; rmatr >= 0; rmatr--)
            {
                res_intensity[index] += coreX[rmatr] * input[index1 - rmatr];

            }
            index++;
            index1++;
        }
    }
    return res_intensity;
}

double * SimpleFilter::yConvolution(const double *input, int height, int width)
{
    int index;
    double *res_intensity = new double [height * width];
    for(int col = 0; col < width; col++)
    {
        for(int row = 0; row < height; row++)
        {
            index = row * width + col;
            res_intensity[index] = 0;
            for(int rmatr = size - 1; rmatr >= 0; rmatr--)
            {
                res_intensity[index] += coreY[rmatr] * input[(row + size - 1 - rmatr) * width + col];
            }
        }
    }
    return res_intensity;
}

QImage * SimpleFilter::sepConvolution(QImage *input)
{
    QImage *expandImage = expander->expand(input, size);
    ImageNormalizer *normalizer = new ImageNormalizer();
    double *or_bits;
    int height, width, resSize;
    height = input->height();
    width = input->width();
    or_bits = normalizer->normalize(expandImage->bits(), expandImage->sizeInBytes(), 1);
    resSize = height * width;
    double *res_intensity = yConvolution(
                    xConvolution(or_bits, height, width),
                    height,
                    width
                );
    uchar *res_bits;
    res_bits = normalizer->toUchar (normalizer->normalize (res_intensity, resSize, 255), resSize);
    return new QImage (res_bits, width, height, width, expandImage->format());
}

QImage *SimpleFilter::fullConvolution(QImage *input)
{
    QImage *expandImage = expander->expand(input, size);
    ImageNormalizer *normalizer = new ImageNormalizer();
    const double *or_bits;
    double a1, a2;
    int height, width, expandWidth, r, index, resSize;
    height = input->height();
    width = input->width();
    expandWidth = expandImage->bytesPerLine();
    or_bits = normalizer->normalize(expandImage->bits(), expandImage->sizeInBytes(), 1);
    resSize = height * width;
    double *res_intensity = new double [resSize];
    r = size / 2;
    a1 = r * expandWidth + r;
    a2 = expandWidth - size;
    for(int row = 0; row < height; row++)
    {
        index = (row + r) * expandWidth + r;
        for(int col = 0; col < width; col++)
        {
            int t_index;
            int index1 = row * width + col;
            res_intensity[index1] = 0;
            t_index = index - a1;
            for(int rmatr = size - 1; rmatr >= 0; rmatr--)
            {
                for(int cmatr = size - 1; cmatr >= 0; cmatr--)
                {
                    res_intensity[index1] += core[rmatr][cmatr] * or_bits[t_index];
                    t_index++;
                }
                t_index += a2;
            }
            index++;
        }
    }
    uchar *res_bits;
    res_bits = normalizer->toUchar (normalizer->normalize (res_intensity, resSize, 255), resSize);
    return new QImage (res_bits, width, height, width, expandImage->format());
}
