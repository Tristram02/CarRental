#ifndef CARRENTAL_STORAGECONTAINER_H
#define CARRENTAL_STORAGECONTAINER_H
#include "ClientRepository.h"
#include "RentRepository.h"
#include "VehicleRepository.h"


class StorageContainer {
private:
    ClientRepository clientRepo;
    RentRepository rentRepo;
    VehicleRepository vehicleRepo;
public:
    //constructor and destructor
    StorageContainer(ClientPtr client, VehiclePtr vehicle,RentPtr rent);
    ~StorageContainer();
    //getters
    ClientRepository &getClientRepo();
    RentRepository &getRentRepo();
    VehicleRepository &getVehicleRepo();
};


#endif //CARRENTAL_STORAGECONTAINER_H
