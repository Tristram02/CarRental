#include "model/Bicycle.h"

Bicycle::Bicycle(const string &newPlateNumber, const unsigned int &newBasePrice) : Vehicle(newPlateNumber, newBasePrice)
{

}

Bicycle::~Bicycle() = default;

//methods

const unsigned int &Bicycle::getEngineDisplacement() const
{
    return Vehicle::getEngineDisplacement();
}

const SegmentType &Bicycle::getSegment() const
{
    return Vehicle::getSegment();
}

double Bicycle::getActualRentalPrice()
{
    return Vehicle::getActualRentalPrice();
}

string Bicycle::getVehicleInfo()
{
    return Vehicle::getVehicleInfo();
}