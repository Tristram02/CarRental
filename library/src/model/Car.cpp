#include "model/Car.h"

Car::Car(const string &newPlateNumber, const unsigned int &newBasePrice, const unsigned int &newEngineDisplacement, const SegmentType &newSegment):
        MotorVehicle(newPlateNumber,newBasePrice, newEngineDisplacement), segment(newSegment)
{

}

Car::~Car() = default;

const unsigned int & Car::getEngineDisplacement() const {
    return MotorVehicle::getEngineDisplacement();
}


const SegmentType &Car::getSegment() const
{
    return segment;
}


//methods

double Car::getActualRentalPrice()
{
    switch (getSegment()) {
        case A:
            return MotorVehicle::getActualRentalPrice()*(A/10.0);
        case B:
            return MotorVehicle::getActualRentalPrice()*(B/10.0);
        case C:
            return MotorVehicle::getActualRentalPrice()*(C/10.0);
        case D:
            return MotorVehicle::getActualRentalPrice()*(D/10.0);
        case E:
            return MotorVehicle::getActualRentalPrice()*(E/10.0);
    }
}

string Car::getVehicleInfo()
{
    switch (getSegment()) {
        case A:
            return MotorVehicle::getVehicleInfo() + " A";
        case B:
            return MotorVehicle::getVehicleInfo() + " B";
        case C:
            return MotorVehicle::getVehicleInfo() + " C";
        case D:
            return MotorVehicle::getVehicleInfo() + " D";
        case E:
            return MotorVehicle::getVehicleInfo() + " E";
    }
}