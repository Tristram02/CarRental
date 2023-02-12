#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H
#include <iostream>
#include <string>

using namespace std;

class Address {
private:
    string city;
    string street;
    string number;

public:
    //constructor
    Address(const string &newCity, const string &newStreet, const string &newNumber);
    //destructor
    ~Address();
    //methods
    string getAddressInfo();
    //getters
    const string &getCity() const;
    const string &getStreet() const;
    const string &getNumber() const;
    //setters
//    void setCity(string newCity);
//    void setStreet(string newStreet);
//    void setNumber(string newNumber);
};


#endif //CARRENTAL_ADDRESS_H
