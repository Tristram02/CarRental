#include "model/Gold.h"

unsigned int Gold::getMaxVehicles()
{
    return 4;
}

double Gold::applyDiscount(double price)
{
    return price * 0.05;
}

string Gold::getTypeInfo()
{
    return "Gold";
}