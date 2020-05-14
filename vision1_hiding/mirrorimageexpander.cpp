#include "mirrorimageexpander.h"

MirrorImageExpander::MirrorImageExpander()
{

}

QImage * MirrorImageExpander::expand(QImage *original, int expand)
{
    int height, width, nwidth, nheight, r;
    const uchar *or_bits;
    uchar *res_bits;
    QImage *img;
    r = expand / 2;
    height = original->height();
    width = original->width();
    nwidth = width + 2 * r;
    nheight = height + 2 * r;
    img = new QImage(nwidth, nheight, original->format());
    int resLineSize = img->bytesPerLine();
    int orLineSize = original->bytesPerLine();
    or_bits = original->constBits();
    res_bits = img->bits();
    for(int i = 0; i < r; i++)
        for(int j = 0; j < width; j++)
        {
            res_bits[i * resLineSize + j + r] = or_bits[(r - i) * orLineSize + j];
            res_bits[(nheight - i - 1) * resLineSize + j + r] = or_bits[(height - 1 - r + i) * orLineSize + j];
        }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < r; j++)
        {
            res_bits[(i + r) * resLineSize + j] = or_bits[i * orLineSize + (r - j)];
            res_bits[(i + r) * resLineSize + nwidth - 1 - j] = or_bits[i * orLineSize + width - 1 - r + j];
        }
        for(int j = 0; j < width; j++)
            res_bits[(i + r) * resLineSize + j + r] = or_bits[i * orLineSize + j];
    }
    for(int iy = 0; iy < r; iy++)
        for(int ix = iy; ix < r; ix++)
        {
            res_bits[iy * resLineSize + ix] = res_bits[iy * resLineSize + (2 * r - ix)];
            res_bits[ix * resLineSize + iy] = res_bits[(2 * r - ix) * resLineSize + iy];
            res_bits[iy * resLineSize + (nwidth - ix - 1)] = res_bits[iy * resLineSize + (width + ix - 1)];
            res_bits[ix * resLineSize + (nwidth - iy - 1)] = res_bits[(2 * r - ix) * resLineSize + (nwidth - iy - 1)];
            res_bits[(nheight - ix - 1) * resLineSize + iy] = res_bits[(height + ix - 1) * resLineSize + iy];
            res_bits[(nheight - iy - 1) * resLineSize + ix] = res_bits[(nheight - iy - 1) * resLineSize + (2 * r - ix)];
            res_bits[(nheight - iy - 1) * resLineSize + (nwidth - ix - 1)] =
                    res_bits[(nheight - iy - 1) * resLineSize + (width + ix - 1)];
            res_bits[(nheight - ix - 1) * resLineSize + (nwidth - iy - 1)] =
                    res_bits[(height + ix - 1) * resLineSize + (nwidth - iy - 1)];
        }
    return img;
}
