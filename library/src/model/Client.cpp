#include "model/Client.h"

//constructor
Client::Client(const string &newFirstName, const string &newLastName, const string &newPersonalID, AddressPtr newAddress, ClientTypePtr newClientType)
    : firstName(newFirstName), lastName(newLastName), personalID(newPersonalID), address(newAddress), clientType(newClientType)
{
    DefaultPtr type = make_shared<Default>();
    setClientType(type);
    archive = false;
}

Client::~Client()
{
//    delete address;
}

//methods

string Client::getClientInfo() {
    return firstName + " " + lastName + " " + personalID + " " + address->getAddressInfo();
}

unsigned int Client::getMaxVehicles()
{
    return clientType->getMaxVehicles();
}

double Client::applyDiscount(double price)
{
    return clientType->applyDiscount(price);
}


//setters

void Client::setfirstName(const string &newFirstName)
{
    if(newFirstName.empty())
        return;
    firstName = newFirstName;
}
void Client::setlastName(const string &newLastName)
{
    if(newLastName.empty())
        return;
    lastName = newLastName;
}

void Client::setAddress(AddressPtr newAddress) {
    if(newAddress == nullptr)
        return;
    address = newAddress;
}

void Client::setClientType(ClientTypePtr newClientType)
{
    clientType = newClientType;
}

void Client::setArchive(bool newArchive)
{
    archive = newArchive;
}


//getters

const string &Client::getfirstName() const {
    return firstName;
}

const string &Client::getlastName() const {
    return lastName;
}

const string &Client::getpersonalID() const {
    return personalID;
}

AddressPtr Client::getAddress() {
    return address;
}

bool Client::isArchive()
{
    return archive;
}