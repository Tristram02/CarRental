#include "model/Diamond.h"

unsigned int Diamond::getMaxVehicles()
{
    return 10;
}

double Diamond::applyDiscount(double price)
{
    if(price > 500)
        return price * 0.4;
    else if(price >250)
        return price * 0.3;
    else if(price > 125)
        return price * 0.2;
    else
        return price * 0.1;
}

string Diamond::getTypeInfo()
{
    return "Diamond";
}