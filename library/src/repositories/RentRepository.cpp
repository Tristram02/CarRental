#include "repositories/RentRepository.h"
#include "model/Rent.h"

RentPtr RentRepository::getRent(unsigned int id) {
    if(id >= Rents.size())
        return nullptr;
    else
        return Rents[id];
}

void RentRepository::addRent(RentPtr newRent) {
    if(newRent == nullptr)
        return;
    else
        Rents.push_back(newRent);
}

void RentRepository::removeRent(RentPtr oldRent) {
    if(oldRent == nullptr)
        return;
    else
        Rents.erase(remove(Rents.begin(), Rents.end(), oldRent), Rents.end());
}

string RentRepository::reportRent() {
    string output = "";
    for(auto x:Rents)
        output += x->getRentInfo() + "\n";
    return output;
}

int RentRepository::sizeRent() {
    return Rents.size();
}

vector<RentPtr> RentRepository::findBy(RentPredicate predicate) const {
    vector<RentPtr> found;
    for(auto x:Rents){
        if(x != nullptr && predicate(x)){
            found.push_back(x);
        }
    }
    return found;
}

vector<RentPtr> RentRepository::findAll() const{
    RentPredicate f = [](RentPtr rent) -> bool {return true;};
    return findBy(f);
}