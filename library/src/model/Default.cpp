#include "model/Default.h"

unsigned int Default::getMaxVehicles()
{
    return 1;
}

double Default::applyDiscount(double price)
{
    return price * 0;
}

string Default::getTypeInfo()
{
    return "Default";
}