#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H
#include "MotorVehicle.h"



class Car:public MotorVehicle {
private:
    SegmentType segment;
public:
    Car(const string &newPlateNumber, const unsigned int &newBasePrice, const unsigned int &newEngineDisplacement, const SegmentType &newSegment);
    ~Car() override;
    //getters
    const SegmentType &getSegment() const override;
    const unsigned int & getEngineDisplacement() const override;

    //methods
    double getActualRentalPrice() override;
    string getVehicleInfo() override;
};


#endif //CARRENTAL_CAR_H
