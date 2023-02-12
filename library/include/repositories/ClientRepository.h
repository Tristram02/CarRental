#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "typedefs.h"

using namespace std;

class ClientRepository {
private:
    vector<ClientPtr> Clients;
public:
    ClientPtr getClient(unsigned int id);
    void addClient(const ClientPtr &newClient);
    void removeClient(const ClientPtr &oldClient);
    string reportClient();
    int sizeClient();
    vector<ClientPtr> findBy(ClientPredicate predicate) const;
    ClientPtr findByPersonalID(string PersonalID);
    vector<ClientPtr> findAll() const;
};


#endif //CARRENTAL_CLIENTREPOSITORY_H
