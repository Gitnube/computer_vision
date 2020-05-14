#include "dxcoregenerator.h"

DXCoreGenerator::DXCoreGenerator()
{

}

double **DXCoreGenerator::generate(int size)
{
    return new double *[3]{
                new double [3]{1, 0, -1},
                new double [3]{2, 0, -2},
                new double [3]{1, 0, -1}
            };
}
