#include "dycoregenerator.h"

DYCoreGenerator::DYCoreGenerator() : ACoreGenerator(true)
{

}

double **DYCoreGenerator::generate(int size)
{
    return new double *[3]{
                new double [3] {1, 2, 1},
                new double [3] {0, 0, 0},
                new double [3] {-1, -2, -1}
            };
}

double * DYCoreGenerator::generateX(int size)
{
    return new double[3] {1, 2, 1};
}

double * DYCoreGenerator::generateY(int size)
{
    return new double[3] {1, 0, -1};
}
