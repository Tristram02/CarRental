#include "managers/RentManager.h"

RentManager::RentManager(RentPtr rent)
{
    currentRents.addRent(rent);
}

RentManager::~RentManager()=default;


vector<RentPtr> RentManager::getAllClientsRents(const ClientPtr &client)
{
    vector<RentPtr> found;
    for(int i =0; i < currentRents.sizeRent(); i++)
    {
        if(currentRents.getRent(i)->getClient() == client)
        {
            found.push_back(currentRents.getRent(i));
        }
    }
    return found;
}

RentPtr RentManager::getAllVehicleRents(const VehiclePtr &vehicle)
{
    for(int i =0; i < currentRents.sizeRent(); i++)
    {
        if(currentRents.getRent(i)->getVehicle() == vehicle)
        {
            return currentRents.getRent(i);
        }
    }
    return nullptr;
}


vector<RentPtr> RentManager::findRents(const RentPredicate &predicate)
{
    return currentRents.findBy(predicate);
}

vector<RentPtr> RentManager::findAllRents()
{
    return currentRents.findAll();
}

double RentManager::checkClientRentBalance(const ClientPtr &client)
{
    double balance = 0;
    for(int i =0; i < archiveRents.sizeRent(); i++)
    {
        if(archiveRents.getRent(i)->getClient() == client)
        {
            balance += archiveRents.getRent(i)->getRentCost();
        }
    }
    return balance;
}

RentPtr RentManager::rentVehicle(const ClientPtr &client, const VehiclePtr &vehicle, const pt::ptime &newBeginTime)
{
    if(client->isArchive())
    {
        return nullptr;
    }
    else if(getAllClientsRents(client).size() >= client->getMaxVehicles())
        return nullptr;
    else if(getAllVehicleRents(vehicle) != nullptr)
        return nullptr;
    else
    {
        RentPtr rent = make_shared<Rent>(findAllRents().size(),client, vehicle, newBeginTime);
        currentRents.addRent(rent);
        return rent;
    }
}

void RentManager::returnVehicle(const VehiclePtr &vehicle)
{
    if(getAllVehicleRents(vehicle) == nullptr)
        return;
    else
    {
        getAllVehicleRents(vehicle)->endRent(pt::not_a_date_time);
        archiveRents.addRent(getAllVehicleRents(vehicle));
        changeClientType(getAllVehicleRents(vehicle)->getClient());
        currentRents.removeRent(getAllVehicleRents(vehicle));
    }
}

void RentManager::changeClientType(const ClientPtr &client)
{
    double bilance = checkClientRentBalance(client);
    if(bilance > 1600.0)
    {
        DiamondPtr d = make_shared<Diamond>();
        client->setClientType(d);
    }
    else if(bilance >= 800)
    {
        PlatinumPtr p = make_shared<Platinum>();
        client->setClientType(p);
    }
    else if(bilance >=400)
    {
        GoldPtr g = make_shared<Gold>();
        client->setClientType(g);
    }
    else if(bilance >= 200)
    {
        SilverPtr s = make_shared<Silver>();
        client->setClientType(s);
    }
    else if(bilance >= 100)
    {
        BronzePtr b = make_shared<Bronze>();
        client->setClientType(b);
    }
    else
    {
        DefaultPtr d = make_shared<Default>();
        client->setClientType(d);
    }
}