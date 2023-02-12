#ifndef WORKSHOP_VEHICLE_H
#define WORKSHOP_VEHICLE_H
#include <iostream>
#include <string>

using namespace std;

enum SegmentType{
    A = 10,
    B = 11,
    C = 12,
    D = 13,
    E = 15
};

class Vehicle {
private:
    string plateNumber;
    unsigned int basePrice;

public:
    Vehicle(const string &newPlateNumber, const unsigned int &newBasePrice);
    virtual ~Vehicle() = 0;
    //methods
    virtual string getVehicleInfo();
    virtual double getActualRentalPrice();
    //getters
    const string &getPlateNumber() const;
    const unsigned int &getBasePrice() const;
    virtual const unsigned int &getEngineDisplacement() const;
    virtual const SegmentType &getSegment() const;
    //setters
    void setPlateNumber(const string &newPlateNumber);
    void setBasePrice(const unsigned int &newBasePrice);

};


#endif //WORKSHOP_VEHICLE_H
