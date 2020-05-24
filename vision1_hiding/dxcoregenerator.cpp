#include "dxcoregenerator.h"

DXCoreGenerator::DXCoreGenerator(): ACoreGenerator(true)
{

}

double **DXCoreGenerator::generate(int size)
{
    return new double *[3]{
                new double [3] {1, 0, -1},
                new double [3] {2, 0, -2},
                new double [3] {1, 0, -1}
            };
}

double * DXCoreGenerator::generateX(int size)
{
    return new double[3] {1, 0, -1};
}

double * DXCoreGenerator::generateY(int size)
{
    return new double[3] {1, 2, 1};
}
