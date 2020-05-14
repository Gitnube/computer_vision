#include "emptyimageexpander.h"

EmptyImageExpander::EmptyImageExpander()
{

}

QImage * EmptyImageExpander::expand(QImage *original, int expand)
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
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
            res_bits[(i + r) * resLineSize + j + r] = or_bits[i * orLineSize + j];
    }
    return img;
}
