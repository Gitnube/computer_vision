#include "mirrorimageexpander.h"

MirrorImageExpander::MirrorImageExpander()
{

}

QImage * MirrorImageExpander::expand(QImage *original, int expand)
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
            res_bits[i * nwidth + j + r] = or_bits[(r - i) * orLineSize + j];
            res_bits[(nheight - i - 1) * nwidth + j + r] = or_bits[(height - 1 - r + i) * orLineSize + j];
        }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < r; j++)
        {
            res_bits[(i + r) * nwidth + j] = or_bits[i * orLineSize + (r - j)];
            res_bits[(i + r) * nwidth + nwidth - 1 - j] = or_bits[i * orLineSize + width - 1 - r + j];
        }
        for(int j = 0; j < width; j++)
            res_bits[(i + r) * nwidth + j + r] = or_bits[i * orLineSize + j];
    }
    for(int iy = 0; iy < r; iy++)
        for(int ix = iy; ix < r; ix++)
        {
            res_bits[iy * nwidth + ix] = res_bits[iy * nwidth + (2 * r - ix)];
            res_bits[ix * nwidth + iy] = res_bits[(2 * r - ix) * nwidth + iy];
            res_bits[iy * nwidth + (nwidth - ix - 1)] = res_bits[iy * nwidth + (width + ix - 1)];
            res_bits[ix * nwidth + (nwidth - iy - 1)] = res_bits[(2 * r - ix) * nwidth + (nwidth - iy - 1)];
            res_bits[(nheight - ix - 1) * nwidth + iy] = res_bits[(height + ix - 1) * nwidth + iy];
            res_bits[(nheight - iy - 1) * nwidth + ix] = res_bits[(nheight - iy - 1) * nwidth + (2 * r - ix)];
            res_bits[(nheight - iy - 1) * nwidth + (nwidth - ix - 1)] =
                    res_bits[(nheight - iy - 1) * nwidth + (width + ix - 1)];
            res_bits[(nheight - ix - 1) * nwidth + (nwidth - iy - 1)] =
                    res_bits[(height + ix - 1) * nwidth + (nwidth - iy - 1)];
        }
    return new QImage(res_bits, nwidth, nheight, nwidth, original->format());
}
