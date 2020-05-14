#include "simplefilter.h"

SimpleFilter::SimpleFilter(ICoreGenerator *generator, int size):
    size(size), generator(generator)
{
    core = generateCore();
}

QImage *SimpleFilter::process(IImageExpander *expander, QImage *img)
{
    this->expander = expander;
    return convolution(img);
}

QImage *SimpleFilter::convolution(QImage *input)
{
    QImage *expandImage = expander->expand(input, size);
    const uchar *or_bits;
    uchar *res_bits;
    double a1, a2;
    int height, width, r, orLineSize, resLineSize, index, index1;
    QImage *img;
    r = size / 2;
    height = expandImage->height() - 2 * r;
    width = expandImage->width() - 2 * r;
    img = new QImage(width, height, expandImage->format());
    orLineSize = expandImage->bytesPerLine();
    resLineSize = img->bytesPerLine();
    or_bits = expandImage->bits();
    res_bits = img->bits();
    width += r;
    height += r;
    a1 = r * orLineSize + r;
    a2 = orLineSize - size;
    for(int row = r; row < height; row++)
    {
        index = row * orLineSize + r;
        index1 = (row - r) * resLineSize;
        for(int col = r; col < width; col++)
        {
            double value_channel;
            int t_index;
            value_channel = 0;
            t_index = index - a1;
            for(int rmatr = size - 1; rmatr >= 0; rmatr--)
            {
                for(int cmatr = size - 1; cmatr >= 0; cmatr--)
                {
                    value_channel += core[rmatr][cmatr] * or_bits[t_index];
                    t_index++;
                }
                t_index += a2;
            }
            if(value_channel > 255)
                value_channel = 255;
            else if(value_channel < 0)
                value_channel = 0;
            res_bits[index1] = value_channel;
            index++;
            index1++;
        }
    }
    return img;
}

double ** SimpleFilter::generateCore()
{
    return generator->generate(size);
}
