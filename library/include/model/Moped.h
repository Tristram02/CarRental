#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H
#include "MotorVehicle.h"

class Moped:public MotorVehicle {
public:
    Moped(const string &newPlateNumber, const unsigned int &newBasePrice, const unsigned int &newEngineDisplacement);
    ~Moped() override;

    const unsigned int & getEngineDisplacement() const override;

    const SegmentType &getSegment() const override;
    //methods
    double getActualRentalPrice() override;
    string getVehicleInfo() override;
};


#endif //CARRENTAL_MOPED_H
