#include <boost/test/unit_test.hpp>
#include "managers/ClientManager.h"

bool testClientFirstName(ClientPtr client){
    return client->getfirstName() == "Karol";
}

struct TestSuiteClientManagerFixture{
    AddressPtr testAddress;
    ClientTypePtr testClientType;
    ClientPtr testClient;

    ClientManagerPtr testClientManager;

    TestSuiteClientManagerFixture()
    {
        testAddress = make_shared<Address>("Krakow", "Politechniki", "12");
        testClient = make_shared<Client>("Kamil", "Wlodarczyk", "KW1", testAddress, testClientType);
        testClientManager = make_shared<ClientManager>(testClient);
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager,TestSuiteClientManagerFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        BOOST_TEST(testClientManager->findAllClients().size() == 1);
    }

    BOOST_AUTO_TEST_CASE(GetClientTestPositive)
    {
        BOOST_TEST(testClientManager->getClient("KW1") == testClient);
    }

    BOOST_AUTO_TEST_CASE(GetClientTestNegative)
    {
        BOOST_TEST(testClientManager->getClient("KW2") == nullptr);
    }

    BOOST_AUTO_TEST_CASE(RegisterClientTestNewClient)
    {
       ClientPtr newTestClient = testClientManager->registerClient("Karol", "Wisniewski", "KW2", testAddress,testClientType);
       BOOST_TEST(testClientManager->findAllClients().size() == 2);
       BOOST_TEST(newTestClient->getfirstName() == "Karol");
       BOOST_TEST(newTestClient->getlastName() == "Wisniewski");
       BOOST_TEST(newTestClient->getpersonalID() == "KW2");
       BOOST_TEST(newTestClient->getAddress() == testAddress);
       BOOST_TEST(newTestClient->isArchive() == false);
    }

    BOOST_AUTO_TEST_CASE(RegisterClientTestExistingClient)
    {
        ClientPtr newTestClient = testClientManager->registerClient("Karol", "Wisniewski", "KW1", testAddress,testClientType);
        BOOST_TEST(newTestClient == testClient);
    }

    BOOST_AUTO_TEST_CASE(UnregisterClientTest)
    {
        testClientManager->unregisterClient(testClient);
        BOOST_TEST(testClient->isArchive());
    }

    BOOST_AUTO_TEST_CASE(FindClientsTest)
    {
        ClientPtr newTestClient = testClientManager->registerClient("Karol", "Wisniewski", "KW2", testAddress,testClientType);
        ClientPtr newTestClient1 = testClientManager->registerClient("Karol", "Wisniewski", "KW3", testAddress,testClientType);
        ClientPtr newTestClient2 = testClientManager->registerClient("Karol", "Wisniewski", "KW4", testAddress,testClientType);
        testClientManager->unregisterClient(newTestClient1);
        BOOST_TEST(testClientManager->findClients(testClientFirstName).size() == 2);//{KW2,KW4}
    }

    BOOST_AUTO_TEST_CASE(FindAllClientsTest)
    {
        ClientPtr newTestClient = testClientManager->registerClient("Karol", "Wisniewski", "KW2", testAddress,testClientType);
        ClientPtr newTestClient1 = testClientManager->registerClient("Karol", "Wisniewski", "KW3", testAddress,testClientType);
        ClientPtr newTestClient2 = testClientManager->registerClient("Karol", "Wisniewski", "KW4", testAddress,testClientType);
        testClientManager->unregisterClient(newTestClient1);
        BOOST_TEST(testClientManager->findAllClients().size() == 3);//{KW1,KW2,KW4}
    }

BOOST_AUTO_TEST_SUITE_END()