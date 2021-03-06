#include "gausscoregenerator.h"
#include "math.h"

GaussCoreGenerator::GaussCoreGenerator(double sigma) : ACoreGenerator(true), sigma(sigma)
{
}

double **GaussCoreGenerator::generate(int size)
{
    double a, **core, sigma2sq;
    int r;
    sigma2sq = 2 * M_PI * sigma * sigma;
    r = size / 2;
    a = 0;
    core = new double *[size];
    for(int i = -r; i <= r; i++)
    {
        core[i + r] = new double [size];
        for(int j = -r; j <= r; j++)
        {
            core[i + r][j + r] = exp( -(i * i + j * j) / sigma2sq );
            a += core[i + r][j + r];
        }
    }
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            core[i][j] /= a;
    return core;
}

double * GaussCoreGenerator::generateX(int size)
{
    double a, *core, sigma2sq;
    int r;
    sigma2sq = 2 * M_PI * sigma * sigma;
    r = size / 2;
    a = 0;
    core = new double [size];
    for(int i = -r; i <= r; i++)
    {
        core[i + r] = exp( -(i * i) / sigma2sq );
        a += core[i + r];
    }
    for(int i = 0; i < size; i++)
        core[i] /= a;
    return core;
}

double * GaussCoreGenerator::generateY(int size)
{
    return generateX(size);
}
