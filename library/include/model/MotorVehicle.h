#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H
#include "Vehicle.h"

class MotorVehicle: public Vehicle{
private:
    unsigned int engineDisplacement;
public:
    MotorVehicle(const string &newPlateNumber, const unsigned int &newBasePrice, const unsigned int &newEngineDisplacement);
    ~MotorVehicle() override = 0;

    //getters
    const unsigned int &getEngineDisplacement() const override;
    const SegmentType &getSegment() const override = 0;
    //methods
    double getActualRentalPrice() override;
    string getVehicleInfo() override;
};


#endif //CARRENTAL_MOTORVEHICLE_H
