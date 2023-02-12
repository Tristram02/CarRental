#include "managers/VehicleManager.h"

VehicleManager::VehicleManager(const VehiclePtr &vehicle)
{
    vehicleRepo.addVehicle(vehicle);
}

VehicleManager::~VehicleManager() = default;


VehiclePtr VehicleManager::getVehicle(const string &PlateNumber)
{
    return vehicleRepo.findByPlateNumber(PlateNumber);
}

VehiclePtr VehicleManager::registerBicycle(const string &newPlateNumber, const unsigned int &newBasePrice)
{
    if(vehicleRepo.findByPlateNumber(newPlateNumber) != nullptr)
    {
        return vehicleRepo.findByPlateNumber(newPlateNumber);
    }
    else
    {
        BicyclePtr bicycle = make_shared<Bicycle>(newPlateNumber, newBasePrice);
        vehicleRepo.addVehicle(bicycle);
        return bicycle;
    }
}

VehiclePtr VehicleManager::registerMoped(const string &newPlateNumber, const unsigned int &newBasePrice, const unsigned int &newEngineDisplacement) {
    if(vehicleRepo.findByPlateNumber(newPlateNumber) != nullptr)
    {
        return vehicleRepo.findByPlateNumber(newPlateNumber);
    }
    else
    {
        MopedPtr moped = make_shared<Moped>(newPlateNumber, newBasePrice, newEngineDisplacement);
        vehicleRepo.addVehicle(moped);
        return moped;
    }
}

VehiclePtr VehicleManager::registerCar(const string &newPlateNumber, const unsigned int &newBasePrice, const unsigned int &newEngineDisplacement, const SegmentType &newSegmentType) {
    if(vehicleRepo.findByPlateNumber(newPlateNumber) != nullptr)
    {
        return vehicleRepo.findByPlateNumber(newPlateNumber);
    }
    else
    {
        CarPtr car = make_shared<Car>(newPlateNumber, newBasePrice, newEngineDisplacement, newSegmentType);
        vehicleRepo.addVehicle(car);
        return car;
    }
}

vector<VehiclePtr> VehicleManager::findVehicles(const VehiclePredicate &predicate)
{
    return vehicleRepo.findBy(predicate);
}

vector<VehiclePtr> VehicleManager::findAllVehicles()
{
    return vehicleRepo.findAll();
}