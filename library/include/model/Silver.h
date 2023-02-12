#ifndef CARRENTAL_SILVER_H
#define CARRENTAL_SILVER_H
#include <iostream>
#include "ClientType.h"

using namespace std;

class Silver:public ClientType {
public:
    unsigned int getMaxVehicles() override;
    double applyDiscount(double price) override;
    string getTypeInfo() override;
};


#endif //CARRENTAL_SILVER_H
