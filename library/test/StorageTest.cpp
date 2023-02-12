#include <boost/test/unit_test.hpp>
#include "repositories/StorageContainer.h"
#include "model/Rent.h"
#include "model/Bicycle.h"

bool testClientPersonalID(ClientPtr client){
    return client->getpersonalID() == "1";
}

bool testVehiclePlateNumber(VehiclePtr vehicle){
    return vehicle->getPlateNumber() == "EL2425";
}

bool testRentID(RentPtr rent){
    return rent->getId() == 1;
}


struct TestSuiteStorageFixture{
    const string testFirstName = "Robert";
    const string testLastName = "Swoboda";
    const string testPersonalID = "1";
    const string testPlateNumber = "EL24RU";
    const unsigned int testBasePrice = 150;
    pt::ptime nadt = pt::not_a_date_time;
    ClientTypePtr testClientType;
    AddressPtr testAddress;
    ClientPtr testClient;
    VehiclePtr testVehicle;
    RentPtr testRent;
    StoragePtr sc;


    TestSuiteStorageFixture() {
        testAddress = make_shared<Address>("Piotrkow", "Wolnosci", "22");
        testClient = make_shared<Client>(testFirstName, testLastName, testPersonalID, testAddress,testClientType);
        testVehicle = make_shared<Bicycle>(testPlateNumber,testBasePrice);
        testRent = make_shared<Rent>(0,testClient,testVehicle,nadt);
        sc = make_shared<StorageContainer>(testClient,testVehicle,testRent);
    }

    ~TestSuiteStorageFixture() {

    }
};


BOOST_FIXTURE_TEST_SUITE(TestSuiteStorage, TestSuiteStorageFixture)

    BOOST_AUTO_TEST_CASE(StorageContructorTest)
    {
        BOOST_TEST(sc->getClientRepo().sizeClient() == 1);
        BOOST_TEST(sc->getVehicleRepo().sizeVehicle() == 1);
        BOOST_TEST(sc->getRentRepo().sizeRent() == 1);
    }

    BOOST_AUTO_TEST_CASE(ClientRepoPositiveTest)
    {
        BOOST_TEST(sc->getClientRepo().getClient(0) == testClient);
        BOOST_TEST(sc->getClientRepo().sizeClient() == 1);
        BOOST_TEST(sc->getClientRepo().reportClient() == testClient->getClientInfo() + "\n");
        sc->getClientRepo().addClient(testClient);
        BOOST_TEST(sc->getClientRepo().sizeClient() == 2);
        sc->getClientRepo().removeClient(testClient);
        BOOST_TEST(sc->getClientRepo().sizeClient() == 0);
    }
    BOOST_AUTO_TEST_CASE(ClientRepoNegativeTest)
    {
        BOOST_TEST(sc->getClientRepo().getClient(1) == nullptr);
        sc->getClientRepo().addClient(nullptr);
        BOOST_TEST(sc->getClientRepo().sizeClient() == 1);
        sc->getClientRepo().removeClient(nullptr);
        BOOST_TEST(sc->getClientRepo().sizeClient() == 1);
    }
    BOOST_AUTO_TEST_CASE(VehicleRepoPositiveTest)
    {
        BOOST_TEST(sc->getVehicleRepo().getVehicle(0) == testVehicle);
        BOOST_TEST(sc->getVehicleRepo().sizeVehicle() == 1);
        BOOST_TEST(sc->getVehicleRepo().reportVehicle() == testVehicle->getVehicleInfo() + "\n");
        sc->getVehicleRepo().addVehicle(testVehicle);
        BOOST_TEST(sc->getVehicleRepo().sizeVehicle() == 2);
        sc->getVehicleRepo().removeVehicle(testVehicle);
        BOOST_TEST(sc->getVehicleRepo().sizeVehicle() == 0);
    }
    BOOST_AUTO_TEST_CASE(VehicleRepoNegativeTest)
    {
        BOOST_TEST(sc->getVehicleRepo().getVehicle(1) == nullptr);
        sc->getVehicleRepo().addVehicle(nullptr);
        BOOST_TEST(sc->getVehicleRepo().sizeVehicle() == 1);
        sc->getVehicleRepo().removeVehicle(nullptr);
        BOOST_TEST(sc->getVehicleRepo().sizeVehicle() == 1);
    }
    BOOST_AUTO_TEST_CASE(RentRepoPositiveTest)
    {
        BOOST_TEST(sc->getRentRepo().getRent(0) == testRent);
        BOOST_TEST(sc->getRentRepo().sizeRent() == 1);
        BOOST_TEST(sc->getRentRepo().reportRent() == testRent->getRentInfo() + "\n");
        sc->getRentRepo().addRent(testRent);
        BOOST_TEST(sc->getRentRepo().sizeRent() == 2);
        sc->getRentRepo().removeRent(testRent);
        BOOST_TEST(sc->getRentRepo().sizeRent() == 0);
    }
    BOOST_AUTO_TEST_CASE(RentRepoNegativeTest)
    {
        BOOST_TEST(sc->getRentRepo().getRent(1) == nullptr);
        sc->getRentRepo().addRent(nullptr);
        BOOST_TEST(sc->getRentRepo().sizeRent() == 1);
        sc->getRentRepo().removeRent(nullptr);
        BOOST_TEST(sc->getRentRepo().sizeRent() == 1);
    }

    BOOST_AUTO_TEST_CASE(PredicateTest)
    {
        ClientPtr c1 = make_shared<Client>("Bartosz", "Krawczyk", "1", testAddress,testClientType);
        ClientPtr c2 = make_shared<Client>("Janina", "Krawczyk", "2", testAddress,testClientType);
        VehiclePtr v1 = make_shared<Bicycle>("EL2425", 220);
        RentPtr r1 = make_shared<Rent>(1,testClient,testVehicle,pt::not_a_date_time);
        sc->getClientRepo().addClient(c1);
        sc->getClientRepo().addClient(c2);
        sc->getVehicleRepo().addVehicle(v1);
        sc->getRentRepo().addRent(r1);

        BOOST_TEST(sc->getClientRepo().findAll().size() == 3);
        BOOST_TEST(sc->getVehicleRepo().findAll().size() == 2);
        BOOST_TEST(sc->getRentRepo().findAll().size() == 2);

        BOOST_TEST(sc->getClientRepo().findBy(testClientPersonalID).size() == 2);
        BOOST_TEST(sc->getVehicleRepo().findBy(testVehiclePlateNumber).size() == 1);
        BOOST_TEST(sc->getRentRepo().findBy(testRentID).size() == 1);
    }


BOOST_AUTO_TEST_SUITE_END()
