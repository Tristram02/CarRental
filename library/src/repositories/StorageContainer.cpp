#include "repositories/StorageContainer.h"

StorageContainer::StorageContainer(ClientPtr client, VehiclePtr vehicle, RentPtr rent) {
    clientRepo.addClient(client);
    vehicleRepo.addVehicle(vehicle);
    rentRepo.addRent(rent);
}

StorageContainer::~StorageContainer() {}

ClientRepository &StorageContainer::getClientRepo() {
    return clientRepo;
}

VehicleRepository &StorageContainer::getVehicleRepo() {
    return vehicleRepo;
}

RentRepository &StorageContainer::getRentRepo() {
    return rentRepo;
}