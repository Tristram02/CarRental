#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H
#include "Vehicle.h"

class Bicycle:public Vehicle {
public:
    Bicycle(const string &newPlateNumber, const unsigned int &newBasePrice);
    ~Bicycle() override;

    const unsigned int & getEngineDisplacement() const override;
//
    const SegmentType &getSegment() const override;

    //methods
    double getActualRentalPrice() override;
    string getVehicleInfo() override;
};


#endif //CARRENTAL_BICYCLE_H
