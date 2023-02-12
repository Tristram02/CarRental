#ifndef CARRENTAL_VEHICLEMANAGER_H
#define CARRENTAL_VEHICLEMANAGER_H
#include "repositories/VehicleRepository.h"
#include "model/Car.h"
#include "model/Bicycle.h"
#include "model/Moped.h"

class VehicleManager {
private:
    VehicleRepository vehicleRepo;
public:
    VehicleManager(const VehiclePtr &vehicle);
    ~VehicleManager();

    VehiclePtr getVehicle(const string &PlateNumber);

    VehiclePtr registerBicycle(const string &newPlateNumber, const unsigned int &newBasePrice);
    VehiclePtr registerMoped(const string &newPlateNumber, const unsigned int &newBasePrice, const unsigned int &newEngineDisplacement);
    VehiclePtr registerCar(const string &newPlateNumber, const unsigned int &newBasePrice, const unsigned int &newEngineDisplacement, const SegmentType &newSegmentType);

    vector<VehiclePtr> findVehicles(const VehiclePredicate &predicate);
    vector<VehiclePtr> findAllVehicles();
};


#endif //CARRENTAL_VEHICLEMANAGER_H
