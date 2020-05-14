#ifndef MIRRORIMAGEEXPANDER_H
#define MIRRORIMAGEEXPANDER_H

#include "iimageexpander.h"

class MirrorImageExpander : public IImageExpander
{
public:
    MirrorImageExpander();
    QImage * expand(QImage *original, int expand) override;
};

#endif // MIRRORIMAGEEXPANDER_H
