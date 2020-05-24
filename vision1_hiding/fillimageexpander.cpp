#include "fillimageexpander.h"

FillImageExpander::FillImageExpander()
{

}

QImage * FillImageExpander::expand(QImage *original, int expand)
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
        {
            res_bits[i * nwidth + j + r] = or_bits[j];
            res_bits[(nheight - i - 1) * nwidth + j + r] = or_bits[(height - 1) * orLineSize + j];
        }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < r; j++)
        {
            res_bits[(i + r) * nwidth + j] = or_bits[i * orLineSize];
            res_bits[(i + r) * nwidth + nwidth - 1 - j] = or_bits[i * orLineSize + width - 1];
        }
        for(int j = 0; j < width; j++)
            res_bits[(i + r) * nwidth + j + r] = or_bits[i * orLineSize + j];
    }
    for(int iy = 0; iy < r; iy++)
        for(int ix = 0; ix < r; ix++)
        {
            res_bits[iy * nwidth + ix] = or_bits[r];
            res_bits[iy * nwidth + (nwidth - ix - 1)] = or_bits[width - 1];
            res_bits[(nheight - ix - 1) * nwidth + iy] = or_bits[(height - 1) * orLineSize];
            res_bits[(nheight - iy - 1) * nwidth + (nwidth - ix - 1)] =
                    or_bits[(height - 1) * orLineSize + (width - 1)];
        }
    return new QImage(res_bits, nwidth, nheight, nwidth, original->format());;
}
