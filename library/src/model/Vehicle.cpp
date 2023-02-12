#include "../../include/model/Vehicle.h"

//constructor and destructor
Vehicle::Vehicle(const string &newPlateNumber, const unsigned int &newBasePrice)
                :plateNumber(newPlateNumber), basePrice(newBasePrice)
{

}

Vehicle::~Vehicle() = default;

const unsigned int &Vehicle::getEngineDisplacement() const
{}

const SegmentType &Vehicle::getSegment() const
{

}

//getters
const string &Vehicle::getPlateNumber() const {
    return plateNumber;
}

const unsigned int &Vehicle::getBasePrice() const {
    return basePrice;
}



//setters

void Vehicle::setPlateNumber(const string &newPlateNumber) {
    if(newPlateNumber.empty())
        return;
    plateNumber = newPlateNumber;
}

void Vehicle::setBasePrice(const unsigned int &newBasePrice) {
    basePrice = newBasePrice;
}


//methods

string Vehicle::getVehicleInfo() {
    return plateNumber + " " + to_string(basePrice);
}

double Vehicle::getActualRentalPrice()
{
    return basePrice;
}