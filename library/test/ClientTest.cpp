#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Default.h"
#include "model/Bronze.h"
#include "model/Silver.h"
#include "model/Gold.h"
#include "model/Platinum.h"
#include "model/Diamond.h"

struct TestSuiteClientFixture{
    const string testFirstName = "Robert";
    const string testLastName = "Swoboda";
    const string testPersonalID = "1";
    AddressPtr testAddress1;
    AddressPtr testAddress2;
    AddressPtr emptyPtr;
    ClientTypePtr testClientType;
    DefaultPtr testDefault;
    BronzePtr testBronze;
    SilverPtr testSilver;
    GoldPtr testGold;
    PlatinumPtr testPlatinum;
    DiamondPtr testDiamond;
    ClientPtr testClient;


    TestSuiteClientFixture() {
        testAddress1 = make_shared<Address>("Piotrkow", "Wolnosci", "22");
        testAddress2 = make_shared<Address>("Krakow", "Tuwima", "12");
        testClient = make_shared<Client>(testFirstName, testLastName, testPersonalID, testAddress1, testClientType);
        testDefault = make_shared<Default>();
        testBronze = make_shared<Bronze>();
        testSilver = make_shared<Silver>();
        testGold = make_shared<Gold>();
        testPlatinum = make_shared<Platinum>();
        testDiamond = make_shared<Diamond>();
        emptyPtr = nullptr;
    }

    ~TestSuiteClientFixture() {

    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        BOOST_TEST(testClient->getfirstName() == testFirstName);
        BOOST_TEST(testClient->getlastName() == testLastName);
        BOOST_TEST(testClient->getpersonalID() == testPersonalID);
        BOOST_TEST(testAddress1 == testClient->getAddress());
        BOOST_TEST(testClient->getMaxVehicles() == testDefault->getMaxVehicles());
        BOOST_TEST(testClient->applyDiscount(10.0) == testDefault->applyDiscount(10.0));
    }

    BOOST_AUTO_TEST_CASE(SettersChangeTest){
        testClient->setfirstName("Marian");
        testClient->setlastName("Kowalski");
        testClient->setAddress(testAddress2);
        testClient->setClientType(testBronze);
        BOOST_TEST(testClient->getfirstName() == "Marian");
        BOOST_TEST(testClient->getlastName() == "Kowalski");
        BOOST_TEST(testClient->getAddress() == testAddress2);
    }
    BOOST_AUTO_TEST_CASE(SettersNotChangeTest){
        testClient->setfirstName("");
        testClient->setlastName("");
        testClient->setAddress(emptyPtr);
        BOOST_TEST(testClient->getfirstName() == testFirstName);
        BOOST_TEST(testClient->getlastName() == testLastName);
        BOOST_TEST(testClient->getAddress() == testAddress1);
    }

    BOOST_AUTO_TEST_CASE(DefaultTypeTest)
    {
        BOOST_TEST(testDefault->getMaxVehicles() == 1);
        BOOST_TEST(testDefault->applyDiscount(10.0) == 0);
    }
    BOOST_AUTO_TEST_CASE(BronzeTypeTest)
    {
        BOOST_TEST(testBronze->getMaxVehicles() == 2);
        BOOST_TEST(testBronze->applyDiscount(10.0) == 3.0);
    }
    BOOST_AUTO_TEST_CASE(SilverTypeTest)
    {
        BOOST_TEST(testSilver->getMaxVehicles() == 3);
        BOOST_TEST(testSilver->applyDiscount(10.0) == 6.0);
    }
    BOOST_AUTO_TEST_CASE(GoldTypeTest)
    {
        BOOST_TEST(testGold->getMaxVehicles() == 4);
        BOOST_TEST(testGold->applyDiscount(10.0) == 10.0*0.05);
    }
    BOOST_AUTO_TEST_CASE(PlatinumTypeTest)
    {
        BOOST_TEST(testPlatinum->getMaxVehicles() == 5);
        BOOST_TEST(testPlatinum->applyDiscount(10.0) == 10.0*0.1);
    }
    BOOST_AUTO_TEST_CASE(DiamondTypeTest)
    {
        BOOST_TEST(testDiamond->getMaxVehicles() == 10);
        BOOST_TEST(testDiamond->applyDiscount(10.0) == 10.0*0.1);
        BOOST_TEST(testDiamond->applyDiscount(125.0) == 125.0*0.1);
        BOOST_TEST(testDiamond->applyDiscount(130.0) == 130.0*0.2);
        BOOST_TEST(testDiamond->applyDiscount(250.0) == 250.0*0.2);
        BOOST_TEST(testDiamond->applyDiscount(300.0) == 300.0*0.3);
        BOOST_TEST(testDiamond->applyDiscount(500.0) == 500.0*0.3);
        BOOST_TEST(testDiamond->applyDiscount(550.0) == 550.0*0.4);
    }

BOOST_AUTO_TEST_SUITE_END()