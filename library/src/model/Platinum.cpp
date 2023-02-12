#include "model/Platinum.h"

unsigned int Platinum::getMaxVehicles()
{
    return 5;
}

double Platinum::applyDiscount(double price)
{
    return price * 0.1;
}

string Platinum::getTypeInfo()
{
    return "Platinum";
}