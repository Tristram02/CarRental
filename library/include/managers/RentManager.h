#ifndef CARRENTAL_RENTMANAGER_H
#define CARRENTAL_RENTMANAGER_H
#include "repositories/RentRepository.h"
#include "model/Rent.h"
#include "model/Client.h"

class RentManager {
private:
    RentRepository currentRents;
    RentRepository archiveRents;

public:
    RentManager(RentPtr rent);
    ~RentManager();

    vector<RentPtr> getAllClientsRents(const ClientPtr &client);
    RentPtr getAllVehicleRents(const VehiclePtr &vehicle);

    vector<RentPtr> findRents(const RentPredicate &predicate);
    vector<RentPtr> findAllRents();

    double checkClientRentBalance(const ClientPtr &client);

    RentPtr rentVehicle(const ClientPtr &client, const VehiclePtr &vehicle, const pt::ptime &newBeginTime);
    void returnVehicle(const VehiclePtr &vehicle);
    void changeClientType(const ClientPtr &client);
};


#endif //CARRENTAL_RENTMANAGER_H
