#include <boost/test/unit_test.hpp>
#include "model/Car.h"
#include "model/Bicycle.h"
#include "typedefs.h"
#include "model/Moped.h"


struct TestSuiteVehicleFixture{
    const string testPlateNumber = "ERA12A3";
    const unsigned int testBasePrice = 110;
    const unsigned int testEngineDisplacement = 1500;
    VehiclePtr a;
    BicyclePtr b;//bicycle
    MotorVehiclePtr mv;//motor vehicle
    MopedPtr m;//moped
    CarPtr c;//car
    TestSuiteVehicleFixture()
    {
        a = make_shared<Bicycle>(testPlateNumber, testBasePrice);
        b = make_shared<Bicycle>(testPlateNumber, testBasePrice);
        mv = make_shared<Moped>(testPlateNumber,testBasePrice,testEngineDisplacement);
        m = make_shared<Moped>(testPlateNumber, testBasePrice,testEngineDisplacement);
        c = make_shared<Car>(testPlateNumber, testBasePrice, testEngineDisplacement, B);
    }
    ~TestSuiteVehicleFixture()
    {
        
    }
};


BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle, TestSuiteVehicleFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        BOOST_TEST(a->getPlateNumber() == testPlateNumber);
        BOOST_TEST(a->getBasePrice() == testBasePrice);
    }
    BOOST_AUTO_TEST_CASE(SettersChangeTest) {
        a->setPlateNumber("ERA13A4");
        a->setBasePrice(120);
        BOOST_TEST(a->getPlateNumber() == "ERA13A4");
        BOOST_TEST(a->getBasePrice() == 120);
    }

    BOOST_AUTO_TEST_CASE(SettersNotChangeTest) {
        a->setPlateNumber("");
        BOOST_TEST(a->getPlateNumber() == testPlateNumber);
    }

    BOOST_AUTO_TEST_CASE(BicycleTest)
    {
        BOOST_TEST(b->getPlateNumber() == testPlateNumber);
        BOOST_TEST(b->getBasePrice() == testBasePrice);
        BOOST_TEST(b->getActualRentalPrice() == testBasePrice);
        BOOST_TEST(b->getVehicleInfo() == testPlateNumber + " " + to_string(testBasePrice));
    }
    BOOST_AUTO_TEST_CASE(MotorVehicleTest)
    {
        BOOST_TEST(mv->getPlateNumber() == testPlateNumber);
        BOOST_TEST(mv->getBasePrice() == testBasePrice);
        BOOST_TEST(mv->getEngineDisplacement() == testEngineDisplacement);
        BOOST_TEST(mv->getActualRentalPrice() == (1.0+(testEngineDisplacement - 1000.0) / 1000.0 * 0.5) * testBasePrice);
        BOOST_TEST(mv->getVehicleInfo() == testPlateNumber + " " + to_string(testBasePrice) + " " + to_string(testEngineDisplacement));
    }
    BOOST_AUTO_TEST_CASE(MopedTest)
    {
        BOOST_TEST(m->getPlateNumber() == testPlateNumber);
        BOOST_TEST(m->getBasePrice() == testBasePrice);
        BOOST_TEST(m->getEngineDisplacement() == testEngineDisplacement);
        BOOST_TEST(m->getActualRentalPrice() == (1.0+(testEngineDisplacement - 1000.0) / 1000.0 * 0.5) * testBasePrice);
        BOOST_TEST(m->getVehicleInfo() == testPlateNumber + " " + to_string(testBasePrice) + " " + to_string(testEngineDisplacement));
    }
    BOOST_AUTO_TEST_CASE(CarTest)
    {
        BOOST_TEST(c->getPlateNumber() == testPlateNumber);
        BOOST_TEST(c->getBasePrice() == testBasePrice);
        BOOST_TEST(c->getEngineDisplacement() == testEngineDisplacement);
        BOOST_TEST(c->getSegment() == B);
        BOOST_TEST(c->getActualRentalPrice() == ((1.0+(testEngineDisplacement - 1000.0) / 1000.0 * 0.5) * testBasePrice) * (B/10.0));
        BOOST_TEST(c->getVehicleInfo() == testPlateNumber + " " + to_string(testBasePrice) + " " + to_string(testEngineDisplacement)+ " B");
    }
BOOST_AUTO_TEST_SUITE_END()