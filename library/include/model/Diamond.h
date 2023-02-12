#ifndef CARRENTAL_DIAMOND_H
#define CARRENTAL_DIAMOND_H
#include <iostream>
#include "ClientType.h"

using namespace std;

class Diamond:public ClientType {
public:
    unsigned int getMaxVehicles() override;
    double applyDiscount(double price) override;
    string getTypeInfo() override;
};


#endif //CARRENTAL_DIAMOND_H
