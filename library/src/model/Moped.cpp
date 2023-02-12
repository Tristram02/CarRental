#include "model/Moped.h"

Moped::Moped(const string &newPlateNumber, const unsigned int &newBasePrice, const unsigned int &newEngineDisplacement) :
        MotorVehicle(newPlateNumber, newBasePrice, newEngineDisplacement)
{

}

Moped::~Moped()=default;

const unsigned int & Moped::getEngineDisplacement() const {
    return MotorVehicle::getEngineDisplacement();
}

const SegmentType &Moped::getSegment() const
{
    return MotorVehicle::getSegment();
}

//methods

double Moped::getActualRentalPrice()
{
    return MotorVehicle::getActualRentalPrice();
}

string Moped::getVehicleInfo()
{
    return MotorVehicle::getVehicleInfo();
}