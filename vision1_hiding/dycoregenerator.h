#ifndef DYCOREGENERATOR_H
#define DYCOREGENERATOR_H

#include "icoregenerator.h"

class DYCoreGenerator : public ICoreGenerator
{
public:
    DYCoreGenerator();
    double **generate(int size) override;
};

#endif // DYCOREGENERATOR_H
