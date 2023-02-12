#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H
#include <iostream>


class ClientType {
public:
    virtual ~ClientType() = default;
    virtual unsigned int getMaxVehicles() = 0;
    virtual double applyDiscount(double price) = 0;
    virtual std::string getTypeInfo() = 0;
};


#endif //CARRENTAL_CLIENTTYPE_H
