#ifndef CARRENTAL_DEFAULT_H
#define CARRENTAL_DEFAULT_H
#include <iostream>
#include "ClientType.h"

using namespace std;

class Default:public virtual ClientType {
public:
    unsigned int getMaxVehicles() override;
    double applyDiscount(double price) override;
    string getTypeInfo() override;
};


#endif //CARRENTAL_DEFAULT_H
