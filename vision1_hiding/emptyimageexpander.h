#ifndef EMPTYIMAGEEXPANDER_H
#define EMPTYIMAGEEXPANDER_H

#include "iimageexpander.h"

class EmptyImageExpander : public IImageExpander
{
public:
    EmptyImageExpander();
    QImage * expand(QImage *original, int expand) override;
};

#endif // EMPTYIMAGEEXPANDER_H
