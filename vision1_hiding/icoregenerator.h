#ifndef ICOREGENERATOR_H
#define ICOREGENERATOR_H


class ICoreGenerator
{
public:
    virtual double **generate(int size) = 0;
    virtual bool isSeparable() = 0;
    virtual double * generateX(int size) = 0;
    virtual double * generateY(int size) = 0;
};

#endif // ICOREGENERATOR_H
