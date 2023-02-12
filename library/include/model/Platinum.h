#ifndef CARRENTAL_PLATINUM_H
#define CARRENTAL_PLATINUM_H
#include <iostream>
#include "ClientType.h"

using namespace std;

class Platinum:public ClientType {
public:
    unsigned int getMaxVehicles() override;
    double applyDiscount(double price) override;
    string getTypeInfo() override;
};


#endif //CARRENTAL_PLATINUM_H
