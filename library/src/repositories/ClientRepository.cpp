#include "repositories/ClientRepository.h"
#include "model/Client.h"



ClientPtr ClientRepository::getClient(unsigned int id){
    if(id >= Clients.size())
        return nullptr;
    else
        return Clients[id];
}

void ClientRepository::addClient(const ClientPtr &newClient) {
    if(newClient == nullptr)
        return;
    else
        Clients.push_back(newClient);
}

void ClientRepository::removeClient(const ClientPtr &oldClient) {
    if(oldClient == nullptr)
        return;
    else
        Clients.erase(remove(Clients.begin(), Clients.end(), oldClient), Clients.end());
}

string ClientRepository::reportClient(){
    stringstream ss;
    for(auto x:Clients)
        ss << x->getClientInfo() + "\n";
    return ss.str();
}

int ClientRepository::sizeClient(){
    return Clients.size();
}

vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate) const {
    vector<ClientPtr> found;
    for(auto x:Clients){
        if(x != nullptr && predicate(x)){
            found.push_back(x);
        }
    }
    return found;
}

ClientPtr ClientRepository::findByPersonalID(string PersonalID)
{
    for(auto x: Clients)
    {
        if(x->getpersonalID() == PersonalID)
            return x;
    }
    return nullptr;
}

vector<ClientPtr> ClientRepository::findAll() const{
    ClientPredicate f = [](ClientPtr client) -> bool {return true;};
    return findBy(f);
}