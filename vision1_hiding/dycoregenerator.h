#ifndef DYCOREGENERATOR_H
#define DYCOREGENERATOR_H

#include "acoregenerator.h"

class DYCoreGenerator : public ACoreGenerator
{
public:
    DYCoreGenerator();
    double **generate(int size) override;
    double * generateX(int size) override;
    double * generateY(int size) override;
};

#endif // DYCOREGENERATOR_H
