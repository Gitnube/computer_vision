#ifndef FILLIMAGEEXPANDER_H
#define FILLIMAGEEXPANDER_H

#include "iimageexpander.h"

class FillImageExpander : public IImageExpander
{
public:
    FillImageExpander();
    QImage * expand(QImage *original, int expand) override;
};

#endif // FILLIMAGEEXPANDER_H
