#include "model/Silver.h"

unsigned int Silver::getMaxVehicles()
{
    return 3;
}

double Silver::applyDiscount(double price)
{
    return 6.0;
}

string Silver::getTypeInfo()
{
    return "Silver";
}