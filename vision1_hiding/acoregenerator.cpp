#include "acoregenerator.h"

ACoreGenerator::ACoreGenerator(bool separability): separability(separability)
{

}

bool ACoreGenerator::isSeparable()
{
    return separability;
}
