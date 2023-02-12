#include <boost/test/unit_test.hpp>
#include "managers/VehicleManager.h"

bool testBasePrice(const VehiclePtr &vehicle){
    return vehicle->getBasePrice() == 120;
}

struct TestSuiteVehicleManagerFixture{
    VehiclePtr testBicycle;
    VehiclePtr testMoped;
    VehiclePtr testCar;
    VehicleManagerPtr testVehicleManager;

    TestSuiteVehicleManagerFixture()
    {
        testBicycle = make_shared<Bicycle>("EL0169", 120);
        testMoped = make_shared<Moped>("EL0269", 120, 500);
        testCar = make_shared<Car>("EL0369", 120, 1500, A);
        testVehicleManager = make_shared<VehicleManager>(testBicycle);
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicleManager,TestSuiteVehicleManagerFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        BOOST_TEST(testVehicleManager->findAllVehicles().size() == 1);
    }

    BOOST_AUTO_TEST_CASE(GetVehicleTestPositive)
    {
        BOOST_TEST(testVehicleManager->getVehicle("EL0169") == testBicycle);
    }

    BOOST_AUTO_TEST_CASE(GetVehicleTestNegative)
    {
        BOOST_TEST(testVehicleManager->getVehicle("EL0469") == nullptr);
    }

    BOOST_AUTO_TEST_CASE(RegisterBicycleTestNewBicycle)
    {
        VehiclePtr newBicycle = testVehicleManager->registerBicycle("EL1169", 150);
        BOOST_TEST(testVehicleManager->findAllVehicles().size() == 2);
        BOOST_TEST(newBicycle->getPlateNumber() == "EL1169");
        BOOST_TEST(newBicycle->getBasePrice() == 150);
    }

    BOOST_AUTO_TEST_CASE(RegisterMopedTestNewMoped)
    {
        VehiclePtr newMoped = testVehicleManager->registerMoped("EL1169", 150, 500);
        BOOST_TEST(testVehicleManager->findAllVehicles().size() == 2);
        BOOST_TEST(newMoped->getPlateNumber() == "EL1169");
        BOOST_TEST(newMoped->getBasePrice() == 150);
        BOOST_TEST(newMoped->getEngineDisplacement() == 500);
    }

    BOOST_AUTO_TEST_CASE(RegisterCarTestNewCar)
    {
        VehiclePtr newCar = testVehicleManager->registerCar("EL1169", 150, 1500, A);
        BOOST_TEST(testVehicleManager->findAllVehicles().size() == 2);
        BOOST_TEST(newCar->getPlateNumber() == "EL1169");
        BOOST_TEST(newCar->getBasePrice() == 150);
        BOOST_TEST(newCar->getEngineDisplacement() == 1500);
        BOOST_TEST(newCar->getSegment() == A);
    }

    BOOST_AUTO_TEST_CASE(RegisterBicycleTestExistingBicycle)
    {
        BOOST_TEST(testVehicleManager->registerBicycle("EL0169", 120) == testBicycle);
    }
    BOOST_AUTO_TEST_CASE(RegisterMopedTestExistingMoped)
    {
        VehiclePtr newTestMoped = testVehicleManager->registerMoped("EL0269", 150, 500);
        BOOST_TEST(testVehicleManager->registerMoped("EL0269", 120, 500) == newTestMoped);
    }
    BOOST_AUTO_TEST_CASE(RegisterCarTestExistingCar)
    {
        VehiclePtr newTestCar = testVehicleManager->registerCar("EL0369", 150, 1500, A);
        BOOST_TEST(testVehicleManager->registerCar("EL0369", 120, 1500, A) == newTestCar);
    }

    BOOST_AUTO_TEST_CASE(FindVehicleTest)
    {
        testVehicleManager->registerMoped("EL0269", 150, 500);
        testVehicleManager->registerCar("EL0369", 120, 1500, A);
        BOOST_TEST(testVehicleManager->findVehicles(testBasePrice).size() == 2);
    }

    BOOST_AUTO_TEST_CASE(FindAllClientsTest)
    {
        testVehicleManager->registerMoped("EL0269", 150, 500);
        testVehicleManager->registerCar("EL0369", 120, 1500, A);
        BOOST_TEST(testVehicleManager->findAllVehicles().size() == 3);
    }

BOOST_AUTO_TEST_SUITE_END()
