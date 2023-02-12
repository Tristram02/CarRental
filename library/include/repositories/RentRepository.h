#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "typedefs.h"

using namespace std;
class RentRepository {
private:
    vector<RentPtr> Rents;
public:
    RentPtr getRent(unsigned int id);
    void addRent(RentPtr newRent);
    void removeRent(RentPtr oldRent);
    string reportRent();
    int sizeRent();
    vector<RentPtr> findBy(RentPredicate predicate) const;
    vector<RentPtr> findAll() const;
};


#endif //CARRENTAL_RENTREPOSITORY_H
