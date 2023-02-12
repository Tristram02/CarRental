#include "model/Address.h"

Address::Address(const string &newCity, const string &newStreet, const string &newNumber)
            : city(newCity), street(newStreet), number(newNumber)
{
}

Address::~Address() {

}

//methods
string Address::getAddressInfo() {
    return city + " " + street + " " + number;
}

//getters
const string &Address::getCity() const {
    return city;
}

const string &Address::getStreet() const {
    return street;
}

const string &Address::getNumber() const {
    return number;
}

//setters
//void Address::setCity(string newCity) {
//    if(newCity.empty())
//        return;
//    city = newCity;
//}
//
//void Address::setStreet(string newStreet) {
//    if(newStreet.empty())
//        return;
//    street = newStreet;
//}
//
//void Address::setNumber(string newNumber) {
//    if(newNumber.empty())
//        return;
//    number = newNumber;
//}