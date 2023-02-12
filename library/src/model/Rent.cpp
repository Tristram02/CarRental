#include "model/Rent.h"

Rent::Rent(const unsigned int &newId, ClientPtr newClient, VehiclePtr newVehicle, pt::ptime newBeginTime)
        :id(newId), client(newClient), vehicle(newVehicle)
{
    if(newBeginTime == pt::not_a_date_time)
        beginTime = pt::second_clock::local_time();
    else
        beginTime = pt::not_a_date_time;
    endTime = pt::not_a_date_time;
    rentCost = 0;
}

Rent::~Rent() {

}

//getters

const unsigned int &Rent::getId() const
{
    return id;
}

ClientPtr Rent::getClient() const
{
    return client;
}

VehiclePtr Rent::getVehicle() const
{
    return vehicle;
}

const pt::ptime &Rent::getBeginTime() const {
    return beginTime;
}

const pt::ptime &Rent::getEndTime() const {
    return endTime;
}

//methods

string Rent::getRentInfo() const {
    stringstream ss;
    ss << getBeginTime();
    ss << " ";
    ss << getEndTime();
    string time = ss.str();
    return to_string(id) + ". " + client->getClientInfo() + "\n" + vehicle->getVehicleInfo() + "\n" + time;
}

void Rent::endRent(pt::ptime timeOfEnding)
{
    if(timeOfEnding == pt::not_a_date_time)
    {
        if((pt::second_clock::local_time() > beginTime) && (endTime == pt::not_a_date_time))
        {
            endTime = pt::second_clock::local_time();
            rentCost = getRentDays() * (vehicle->getActualRentalPrice() - client->applyDiscount(vehicle->getActualRentalPrice()));
        }
        else if(endTime == pt::not_a_date_time)
            endTime = beginTime;
    }
    else
    {
        endTime = pt::not_a_date_time;
    }
}

int Rent::getRentDays() const{
    if(endTime == pt::not_a_date_time)
        return 0;
    pt::time_period skew = pt::time_period(beginTime,endTime);
    if((skew.length().hours() == 0) && (skew.length().minutes() == 0))
        return 0;
    return floor(skew.length().hours()/24.0) + 1;
}

double Rent::getRentCost() const{
    return rentCost;
}