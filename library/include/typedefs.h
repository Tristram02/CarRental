#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H
#include <memory>
#include <functional>

using namespace std;

class Client;
class Vehicle;
class MotorVehicle;
class Bicycle;
class Moped;
class Car;
class Address;
class Rent;
class StorageContainer;
class ClientType;
class Default;
class Bronze;
class Silver;
class Gold;
class Platinum;
class Diamond;
class ClientManager;
class VehicleManager;
class RentManager;

typedef shared_ptr<Client> ClientPtr;
typedef shared_ptr<Rent> RentPtr;
typedef shared_ptr<Vehicle> VehiclePtr;
typedef shared_ptr<MotorVehicle> MotorVehiclePtr;
typedef shared_ptr<Bicycle> BicyclePtr;
typedef shared_ptr<Moped> MopedPtr;
typedef shared_ptr<Car> CarPtr;
typedef shared_ptr<Address> AddressPtr;
typedef shared_ptr<StorageContainer> StoragePtr;
typedef shared_ptr<ClientType> ClientTypePtr;
typedef shared_ptr<Default> DefaultPtr;
typedef shared_ptr<Bronze> BronzePtr;
typedef shared_ptr<Silver> SilverPtr;
typedef shared_ptr<Gold> GoldPtr;
typedef shared_ptr<Platinum> PlatinumPtr;
typedef shared_ptr<Diamond> DiamondPtr;
typedef shared_ptr<ClientManager> ClientManagerPtr;
typedef shared_ptr<VehicleManager> VehicleManagerPtr;
typedef shared_ptr<RentManager> RentManagerPtr;

typedef function<bool(ClientPtr)> ClientPredicate;
typedef function<bool(VehiclePtr)> VehiclePredicate;
typedef function<bool(RentPtr)> RentPredicate;



#endif //CARRENTAL_TYPEDEFS_H
