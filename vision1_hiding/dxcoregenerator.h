#ifndef DXCOREGENERATOR_H
#define DXCOREGENERATOR_H

#include "acoregenerator.h"

class DXCoreGenerator : public ACoreGenerator
{
public:
    DXCoreGenerator();
    double **generate(int size) override;
    double * generateX(int size) override;
    double * generateY(int size) override;
};

#endif // DXCOREGENERATOR_H
