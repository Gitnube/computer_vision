#ifndef DXCOREGENERATOR_H
#define DXCOREGENERATOR_H

#include "icoregenerator.h"

class DXCoreGenerator : public ICoreGenerator
{
public:
    DXCoreGenerator();
    double **generate(int size) override;
};

#endif // DXCOREGENERATOR_H
