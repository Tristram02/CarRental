#ifndef WORKSHOP_CLIENT_H
#define WORKSHOP_CLIENT_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Address.h"
#include "Rent.h"
#include "ClientType.h"
#include "Default.h"
#include "Bronze.h"
#include "Silver.h"
#include "Gold.h"
#include "Platinum.h"
#include "Diamond.h"
#include "typedefs.h"

using namespace std;
class Rent;


class Client {
private:
    string firstName;
    string lastName;
    const string personalID;
    AddressPtr address;
    ClientTypePtr clientType;
    bool archive;
public:
    //konstruktor i destruktor
    Client(const string &newFirstName, const string &newLastName, const string &newPersonalID, AddressPtr newAddress, ClientTypePtr newClientType);
    ~Client();
    //metody
    string getClientInfo();
    unsigned int getMaxVehicles();
    double applyDiscount(double price);

    //settery
    void setfirstName(const string &newFirstName);
    void setlastName(const string &newLastName);
    void setAddress(AddressPtr newAddress);
    void setClientType(ClientTypePtr newClientType);
    void setArchive(bool newArchive);

    //gettery
    const string &getfirstName() const;
    const string &getlastName() const;
    const string &getpersonalID() const;
    AddressPtr getAddress();
    bool isArchive();
};


#endif //WORKSHOP_CLIENT_H
