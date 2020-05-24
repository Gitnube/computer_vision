#ifndef GAUSSCOREGENERATOR_H
#define GAUSSCOREGENERATOR_H

#include "acoregenerator.h"

class GaussCoreGenerator : public ACoreGenerator
{
public:
    GaussCoreGenerator(double sigma);
    double **generate(int size) override;
    double * generateX(int size) override;
    double * generateY(int size) override;
private:
    double sigma;
};

#endif // GAUSSCOREGENERATOR_H
