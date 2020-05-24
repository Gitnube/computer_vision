#include "emptyimageexpander.h"

EmptyImageExpander::EmptyImageExpander()
{

}

QImage * EmptyImageExpander::expand(QImage *original, int expand)
{
    int height, width, nwidth, nheight, r;
    const uchar *or_bits;
    uchar *res_bits;
    r = expand / 2;
    height = original->height();
    width = original->width();
    nwidth = width + 2 * r;
    nheight = height + 2 * r;
    int orLineSize = original->bytesPerLine();
    or_bits = original->constBits();
    res_bits = new uchar[nwidth * nheight];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < width; j++)
            res_bits[i * nwidth + j] = 0;
    for(int i = 0; i < height; i++)
    {
        int strIndex = i * nwidth;
        for(int j = 0; j < r; j++)
            res_bits[strIndex + j] = 0;
        for(int j = 0; j < width; j++)
            res_bits[(i + r) * nwidth + j + r] = or_bits[i * orLineSize + j];
        strIndex += width + r;
        for(int j = 0; j < r; j++)
            res_bits[strIndex + j] = 0;
    }
    for(int i = height + r; i < nheight; i++)
        for(int j = 0; j < nwidth; j++)
            res_bits[i * nwidth + j] = 0;
    return new QImage(res_bits, nwidth, nheight, nwidth, original->format());;
}
