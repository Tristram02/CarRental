#include "model/MotorVehicle.h"

MotorVehicle::MotorVehicle(const string &newPlateNumber, const unsigned int &newBasePrice, const unsigned int &newEngineDisplacement) :
            Vehicle(newPlateNumber, newBasePrice), engineDisplacement(newEngineDisplacement)
{

}

MotorVehicle::~MotorVehicle() = default;


//getter
const unsigned int &MotorVehicle::getEngineDisplacement() const
{
    return engineDisplacement;
}

const SegmentType &MotorVehicle::getSegment() const
{

}

//methods

double MotorVehicle::getActualRentalPrice()
{
    if(getEngineDisplacement() < 1000)
        return Vehicle::getActualRentalPrice();
    else if(getEngineDisplacement() >=1000 && getEngineDisplacement() <= 2000)
    {
        return (1+(getEngineDisplacement()-1000.0) / 1000.0 * 0.5) * Vehicle::getActualRentalPrice();
    }
    else
        return Vehicle::getActualRentalPrice()*1.5;
}

string MotorVehicle::getVehicleInfo()
{
    return Vehicle::getVehicleInfo() + " " + to_string(engineDisplacement);
}