#include "managers/ClientManager.h"


ClientManager::ClientManager(ClientPtr client)
{
    clientRepo.addClient(client);
}

ClientManager::~ClientManager() {}


ClientPtr ClientManager::getClient(const string &PersonalID)
{
    return clientRepo.findByPersonalID(PersonalID);
}

ClientPtr ClientManager::registerClient(const string &newFirstName, const string &newLastName, const string &newPersonalID,
                                        const AddressPtr &newAddress, const ClientTypePtr &newClientType)
{
    if(clientRepo.findByPersonalID(newPersonalID) != nullptr)
        return clientRepo.findByPersonalID(newPersonalID);
    else
    {
        ClientPtr newClient = make_shared<Client>(newFirstName, newLastName, newPersonalID, newAddress, newClientType);
        clientRepo.addClient(newClient);
        return newClient;
    }
}

void ClientManager::unregisterClient(const ClientPtr& oldClient)
{
    if(getClient(oldClient->getpersonalID()) != nullptr)
        oldClient->setArchive(true);
}

vector<ClientPtr> ClientManager::findClients(const ClientPredicate &predicate)
{
    ClientPredicate f = [predicate](const ClientPtr &client)->bool
            {
                if(predicate(client) && (!client->isArchive()))
                    return true;
                else
                    return false;
            };
    return clientRepo.findBy(f);
}

vector<ClientPtr> ClientManager::findAllClients()
{
    ClientPredicate f = [](const ClientPtr &client) ->bool{return true;};
    return findClients(f);
}