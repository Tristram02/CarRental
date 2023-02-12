#include <boost/test/unit_test.hpp>
#define private public
#include "model/Rent.h"
#include "managers/RentManager.h"
#include "model/Bicycle.h"

bool testClientFirstName(RentPtr rent){
    return rent->getClient()->getfirstName() == "Kamil";
}

struct TestSuiteRentManagerFixture{
    AddressPtr testAddress;
    ClientTypePtr testClientType;
    ClientPtr testClient;

    VehiclePtr testVehicle;

    RentPtr testRent;

    RentManagerPtr testRentManager;

    TestSuiteRentManagerFixture()
    {
        testAddress = make_shared<Address>("Krakow", "Politechniki", "12");
        testClient = make_shared<Client>("Kamil", "Wlodarczyk", "KW1", testAddress, testClientType);
        testVehicle = make_shared<Bicycle>("EL0169", 150);
        testRent = make_shared<Rent>(0,testClient, testVehicle, pt::not_a_date_time);
        testRentManager = make_shared<RentManager>(testRent);
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentManager,TestSuiteRentManagerFixture)
//
    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        BOOST_TEST(testRentManager->findAllRents().size() == 1);
    }

    BOOST_AUTO_TEST_CASE(RentVehiclePositiveTest)
    {
        GoldPtr testGoldClient = make_shared<Gold>();
        testClient->setClientType(testGoldClient);
        VehiclePtr newTestVehicle = make_shared<Bicycle>("EL0069", 320);
        RentPtr newTestRent = testRentManager->rentVehicle(testClient,newTestVehicle,pt::not_a_date_time);
        BOOST_TEST_REQUIRE(newTestRent != nullptr);
        BOOST_TEST_REQUIRE(testRentManager->findAllRents().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(RentVehicleNegativeTest)
    {
        VehiclePtr newTestVehicle = make_shared<Bicycle>("EL0069", 320);
        VehiclePtr newTestVehicle1 = make_shared<Bicycle>("EL0069", 320);
        ClientPtr newTestClient = make_shared<Client>("Kuba", "Bedoes", "KB2115", testAddress,testClientType);
        ClientPtr newTestClient2 = make_shared<Client>("Andrzej", "Bedoes", "AB2115", testAddress,testClientType);
        newTestClient->setArchive(true);
        RentPtr newTestRent = testRentManager->rentVehicle(newTestClient,newTestVehicle,pt::not_a_date_time);
        RentPtr newTestRent1 = testRentManager->rentVehicle(testClient,newTestVehicle1,pt::not_a_date_time);
        RentPtr newTestRent2 = testRentManager->rentVehicle(newTestClient2,testVehicle,pt::not_a_date_time);
        BOOST_TEST_REQUIRE(newTestRent == nullptr);
        BOOST_TEST_REQUIRE(newTestRent1 == nullptr);
        BOOST_TEST_REQUIRE(newTestRent2 == nullptr);
        BOOST_TEST_REQUIRE(testRentManager->findAllRents().size() == 1);
    }

    BOOST_AUTO_TEST_CASE(GetAllClientsRentsTest)
    {
        BOOST_TEST(testRentManager->getAllClientsRents(testClient).size() == 1);
        GoldPtr testGoldClient = make_shared<Gold>();
        testClient->setClientType(testGoldClient);
        VehiclePtr newTestVehicle = make_shared<Bicycle>("EL0269", 150);
        RentPtr newTestRent = testRentManager->rentVehicle(testClient,newTestVehicle,pt::not_a_date_time);
        BOOST_TEST(testRentManager->getAllClientsRents(testClient).size() == 2);
    }

    BOOST_AUTO_TEST_CASE(GetAllVehicleRentsPositive)
    {
        BOOST_TEST(testRentManager->getAllVehicleRents(testVehicle) == testRent);
    }

    BOOST_AUTO_TEST_CASE(GetAllVehicleRentsNegative)
    {
        VehiclePtr newTestVehicle = make_shared<Bicycle>("EL0269", 150);
        BOOST_TEST(testRentManager->getAllVehicleRents(newTestVehicle) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(FindRentsTest)
    {
        ClientPtr newTestClient = make_shared<Client>("Karol", "Wisniewski", "KW2", testAddress,testClientType);
        ClientPtr newTestClient1 = make_shared<Client>("Kuba", "Wisniewski", "KW3", testAddress,testClientType);
        ClientPtr newTestClient2 = make_shared<Client>("Kamil", "Wisniewski", "KW4", testAddress,testClientType);
        VehiclePtr newTestVehicle = make_shared<Bicycle>("EL0369", 150);
        VehiclePtr newTestVehicle1 = make_shared<Bicycle>("EL0469", 150);
        VehiclePtr newTestVehicle2 = make_shared<Bicycle>("EL0569", 150);
        RentPtr newTestRent = testRentManager->rentVehicle(newTestClient,newTestVehicle,pt::not_a_date_time);
        RentPtr newTestRent1 = testRentManager->rentVehicle(newTestClient1,newTestVehicle1,pt::not_a_date_time);
        RentPtr newTestRent2 = testRentManager->rentVehicle(newTestClient2,newTestVehicle2,pt::not_a_date_time);
        BOOST_TEST(testRentManager->findRents(testClientFirstName).size() == 2);
    }

    BOOST_AUTO_TEST_CASE(FindAllRentsTest)
    {
        ClientPtr newTestClient = make_shared<Client>("Karol", "Wisniewski", "KW2", testAddress,testClientType);
        VehiclePtr newTestVehicle = make_shared<Bicycle>("EL0369", 150);
        RentPtr newTestRent = testRentManager->rentVehicle(newTestClient,newTestVehicle,pt::not_a_date_time);
        BOOST_TEST(testRentManager->findAllRents().size() == 2);//{KW1,KW2,KW4}
    }

    BOOST_AUTO_TEST_CASE(ReturnVehicleTestPositive)
    {
        testRentManager->findAllRents()[0]->beginTime = pt::second_clock::local_time() - pt::hours(24);
        testRentManager->returnVehicle(testVehicle);
        BOOST_TEST(testRentManager->findAllRents().size() == 0);
    }

    BOOST_AUTO_TEST_CASE(ReturnVehicleTestNegative)
    {
        VehiclePtr newTestVehicle = make_shared<Bicycle>("EL0469", 220);
        testRentManager->returnVehicle(newTestVehicle);
        BOOST_TEST(testRentManager->findAllRents().size() == 1);
    }

    BOOST_AUTO_TEST_CASE(CheckClientRentBilanceTest)
    {
        testRentManager->findAllRents()[0]->beginTime = pt::second_clock::local_time() - pt::hours(20);
        testRentManager->returnVehicle(testVehicle);
        BOOST_TEST(testRentManager->checkClientRentBalance(testClient) == testVehicle->getActualRentalPrice());
    }

    BOOST_AUTO_TEST_CASE(ChangeClientTypeTest)
    {
        VehiclePtr newTestVehicle = make_shared<Bicycle>("EL0469", 220);
        testRentManager->findAllRents()[0]->beginTime = pt::second_clock::local_time() - pt::hours(20);
        testRentManager->returnVehicle(testVehicle);
        BOOST_TEST(testClient->getMaxVehicles() == 2);
        testRentManager->rentVehicle(testClient,newTestVehicle,pt::not_a_date_time);
        testRentManager->findAllRents()[0]->beginTime = pt::second_clock::local_time() - pt::hours(20);
        testRentManager->returnVehicle(newTestVehicle);
        BOOST_TEST(testClient->getMaxVehicles() == 3);
    }

BOOST_AUTO_TEST_SUITE_END()