#ifndef GAUSSCOREGENERATOR_H
#define GAUSSCOREGENERATOR_H

#include "icoregenerator.h"

class GaussCoreGenerator : public ICoreGenerator
{
public:
    GaussCoreGenerator(double sigma);
    double **generate(int size) override;
private:
    double sigma;
};

#endif // GAUSSCOREGENERATOR_H
