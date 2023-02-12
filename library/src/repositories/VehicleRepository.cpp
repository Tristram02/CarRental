#include "repositories/VehicleRepository.h"
#include "model/Vehicle.h"

VehiclePtr VehicleRepository::getVehicle(unsigned int id) {
    if(id >= Vehicles.size())
        return nullptr;
    else
        return Vehicles[id];
}

void VehicleRepository::addVehicle(VehiclePtr newVehicle) {
    if(newVehicle == nullptr)
        return;
    else
        Vehicles.push_back(newVehicle);
}

void VehicleRepository::removeVehicle(VehiclePtr oldVehicle) {
    if(oldVehicle == nullptr)
        return;
    else
        Vehicles.erase(remove(Vehicles.begin(), Vehicles.end(), oldVehicle), Vehicles.end());
}

string VehicleRepository::reportVehicle() {
    string output = "";
    for(auto x:Vehicles)
        output += x->getVehicleInfo() + "\n";
    return output;
}

int VehicleRepository::sizeVehicle() {
    return Vehicles.size();
}

vector<VehiclePtr> VehicleRepository::findBy(VehiclePredicate predicate) const {
    vector<VehiclePtr> found;
    for(auto x:Vehicles){
        if(x != nullptr && predicate(x)){
            found.push_back(x);
        }
    }
    return found;
}

VehiclePtr VehicleRepository::findByPlateNumber(const string &PlateNumber) const
{
    for(auto x:Vehicles)
    {
        if(x->getPlateNumber() == PlateNumber)
            return x;
    }
    return nullptr;
}

vector<VehiclePtr> VehicleRepository::findAll() const {
    VehiclePredicate f = [](VehiclePtr vehicle) -> bool { return true; };
    return findBy(f);
}