#ifndef WORKSHOP_RENT_H
#define WORKSHOP_RENT_H
#include "Client.h"
#include "Vehicle.h"
#include "typedefs.h"
#include <boost/date_time.hpp>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Client;

class Rent {
private:
    unsigned int id;
    ClientPtr client;
    VehiclePtr vehicle;
    pt::ptime beginTime;
    pt::ptime endTime;
    double rentCost;
public:
    Rent(const unsigned int &newId, ClientPtr newClient, VehiclePtr newVehicle, pt::ptime newBeginTime);
    ~Rent();
    //methods
    string getRentInfo() const;
    void endRent(pt::ptime timeOfEnding);
    int getRentDays() const;
    double getRentCost() const;
    //getters
    const unsigned int &getId() const;
    ClientPtr getClient() const;
    VehiclePtr getVehicle() const;
    const pt::ptime &getBeginTime() const;
    const pt::ptime &getEndTime() const;
};


#endif //WORKSHOP_RENT_H
