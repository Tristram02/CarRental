#ifndef CARRENTAL_GOLD_H
#define CARRENTAL_GOLD_H
#include <iostream>
#include "ClientType.h"

using namespace std;

class Gold:public ClientType {
public:
    unsigned int getMaxVehicles() override;
    double applyDiscount(double price) override;
    string getTypeInfo() override;
};


#endif //CARRENTAL_GOLD_H
