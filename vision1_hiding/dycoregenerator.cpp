#include "dycoregenerator.h"

DYCoreGenerator::DYCoreGenerator()
{

}

double **DYCoreGenerator::generate(int size)
{
    return new double *[3]{
                new double [3]{1, 2, 1},
                new double [3]{0, 0, 0},
                new double [3]{-1, -2, -1}
            };
}
