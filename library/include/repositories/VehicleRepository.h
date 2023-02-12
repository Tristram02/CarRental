#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "typedefs.h"

using namespace std;

class VehicleRepository {
private:
    vector<VehiclePtr> Vehicles;
public:
    VehiclePtr getVehicle(unsigned int id);
    void addVehicle(VehiclePtr newVehicle);
    void removeVehicle(VehiclePtr oldVehicle);
    string reportVehicle();
    int sizeVehicle();
    vector<VehiclePtr> findBy(VehiclePredicate predicate) const;
    VehiclePtr findByPlateNumber(const string &PlateNumber) const;
    vector<VehiclePtr> findAll() const;
};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
