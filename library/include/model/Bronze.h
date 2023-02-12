#ifndef CARRENTAL_BRONZE_H
#define CARRENTAL_BRONZE_H
#include <iostream>
#include "ClientType.h"

using namespace std;

class Bronze:public ClientType {
public:
    unsigned int getMaxVehicles() override;
    double applyDiscount(double price) override;
    string getTypeInfo() override;
};


#endif //CARRENTAL_BRONZE_H
