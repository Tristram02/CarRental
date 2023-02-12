#include "model/Bronze.h"
unsigned int Bronze::getMaxVehicles()
{
    return 2;
}

double Bronze::applyDiscount(double price)
{
    return 3.0;
}

string Bronze::getTypeInfo()
{
    return "Bronze";
}