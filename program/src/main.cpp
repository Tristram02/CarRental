#include "model/Rent.h"
#include "model/Car.h"
#include "repositories/StorageContainer.h"
#include <boost/date_time.hpp>
#include <boost/thread/thread.hpp>
#include "model/Bicycle.h"
#include "model/MotorVehicle.h"
#include "model/Default.h"
#include "model/ClientType.h"
#include "managers/ClientManager.h"
#include "managers/VehicleManager.h"
#include "managers/RentManager.h"
#include "repositories/ClientRepository.h"

bool testClientFirstName(const ClientPtr& client){
    return client->getfirstName() == "Kamil";
}

bool testVehicleBasePrice(const VehiclePtr& vehicle){
    return vehicle->getBasePrice() == 220;
}

bool testRentClientFirstName(const RentPtr& rent){
    return rent->getClient()->getfirstName() == "Kamil";
}

int main()
{
    ClientTypePtr ct;
    AddressPtr a = make_shared<Address>("Lodz", "Politechniki", "22a");
    ClientPtr c = make_shared<Client>("Kamil", "Stonoga", "KS1",a,ct);
    VehiclePtr b = make_shared<Bicycle>("EL0303", 220);
    RentPtr r = make_shared<Rent>(0,c,b,pt::not_a_date_time);

    ClientManagerPtr cm = make_shared<ClientManager>(c);
    VehicleManagerPtr vm = make_shared<VehicleManager>(b);
    RentManagerPtr rm = make_shared<RentManager>(r);

    ClientPtr client = cm->registerClient("Kuba", "Nafide", "KN1",a,ct);
    for(auto x:cm->findAllClients())
    {
        cout << x->getClientInfo() << "\n";
    }
    for(auto x:cm->findClients(testClientFirstName))
    {
        cout << x->getClientInfo() << "\n";
    }
    cout << "\n------------------------------------------------------------------------------\n";

    VehiclePtr vehicle = vm->registerCar("EL3456", 330, 1500, C);
    for(auto x:vm->findAllVehicles())
    {
        cout << x->getVehicleInfo() << "\n";
    }
    for(auto x:vm->findVehicles(testVehicleBasePrice))
    {
        cout << x->getVehicleInfo() << "\n";
    }
    cout << "\n------------------------------------------------------------------------------\n";

    RentPtr rent = rm->rentVehicle(client,vehicle,pt::not_a_date_time);
    for(auto x:rm->findAllRents())
    {
        cout << x->getRentInfo() << "\n";
    }
    for(auto x:rm->findRents(testRentClientFirstName))
    {
        cout << x->getRentInfo() << "\n";
    }
    cout << "\n------------------------------------------------------------------------------\n";

    rm->returnVehicle(b);

    cout << "Ilosc wypozyczonych samochodow: " << rm->findAllRents().size() << "\n";


    cm->unregisterClient(c);
    cout << c->getfirstName() << " " << ((c->isArchive()) ? "jest" : "nie jest") << " zarchiwizowany";
    return 0;
}
