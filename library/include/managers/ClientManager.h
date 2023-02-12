#ifndef CARRENTAL_CLIENTMANAGER_H
#define CARRENTAL_CLIENTMANAGER_H
#include "repositories/ClientRepository.h"
#include "model/Client.h"

class ClientManager {
private:
    ClientRepository clientRepo;
public:
    ClientManager(ClientPtr client);
    ~ClientManager();

    ClientPtr getClient(const string &PersonalID);
    ClientPtr registerClient(const string &newFirstName, const string &newLastName, const string &newPersonalID, const AddressPtr &newAddress, const ClientTypePtr &newClientType);
    void unregisterClient(const ClientPtr& oldClient);
    vector<ClientPtr> findClients(const ClientPredicate &predicate);
    vector<ClientPtr> findAllClients();
};


#endif //CARRENTAL_CLIENTMANAGER_H
