#ifndef ACOREGENERATOR_H
#define ACOREGENERATOR_H

#include "icoregenerator.h"

class ACoreGenerator: public ICoreGenerator
{
public:
    ACoreGenerator(bool separability);
    virtual double **generate(int size) = 0;
    virtual bool isSeparable();
    virtual double * generateX(int size) = 0;
    virtual double * generateY(int size) = 0;
private:
    bool separability;
};

#endif // ACOREGENERATOR_H
