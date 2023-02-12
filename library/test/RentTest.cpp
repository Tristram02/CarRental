#include <boost/test/unit_test.hpp>
#include <boost/thread/thread.hpp>
#define private public
#include "model/Rent.h"
#include "model/Bicycle.h"


struct TestSuiteRentFixture{
    const unsigned int testId = 1;
    ClientTypePtr testClientType;
    ClientPtr testClient;
    VehiclePtr testVehicle;
    AddressPtr testAddress;
    pt::ptime nadt = pt::not_a_date_time;//nadt = not_a_date_time

    TestSuiteRentFixture() {
        testAddress = make_shared<Address>("Krakow", "Tuwima", "22");
        testClient = make_shared<Client>("Kamil", "Stonoga", "12",testAddress,testClientType);
        testVehicle = make_shared<Bicycle>("ERA12WA", 120);
    }

    ~TestSuiteRentFixture() {

    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        Rent r(testId, testClient, testVehicle, nadt);
        BOOST_TEST(r.getId() == testId);
        BOOST_TEST(r.getClient() == testClient);
        BOOST_TEST(r.getVehicle() == testVehicle);
//        BOOST_TEST(r.getRentInfo() == testClient->getCurrentRents()[0]->getRentInfo());
//        BOOST_TEST(testVehicle->isRented());
    }

    BOOST_AUTO_TEST_CASE(RentBeginTimeTestPositive){
        Rent r(testId, testClient, testVehicle, nadt);
        pt::ptime now = pt::second_clock::local_time();
        BOOST_TEST_REQUIRE(!r.getBeginTime().is_not_a_date_time());
        pt::time_period skew = pt::time_period(r.getBeginTime(), now);
        BOOST_TEST((skew.length().hours() == 0 && skew.length().minutes() == 0));
    }
    BOOST_AUTO_TEST_CASE(RentBeginTimeTestNegtive){
        Rent r(testId, testClient, testVehicle, pt::second_clock::local_time());
        BOOST_TEST_REQUIRE(r.getBeginTime().is_not_a_date_time());
    }
    BOOST_AUTO_TEST_CASE(RentEndTimeTestPositive){
        Rent r(testId, testClient, testVehicle, nadt);
        boost::this_thread::sleep(pt::seconds(1));
        r.endRent(nadt);
        BOOST_TEST_REQUIRE(!r.getEndTime().is_not_a_date_time());
//        BOOST_TEST(!testVehicle->isRented());
//        BOOST_TEST(testClient->getCurrentRents().size() == 0);
    }
    BOOST_AUTO_TEST_CASE(RentEndTimeTestNegative){
        Rent r(testId, testClient, testVehicle, nadt);
        pt::ptime test = pt::ptime(gr::date(2015,5,13),pt::hours(9)+pt::minutes(25));
        r.endRent(test);
        BOOST_TEST_REQUIRE(r.getEndTime().is_not_a_date_time());
        pt::ptime end = pt::second_clock::local_time();
        r.endRent(nadt);
        BOOST_TEST(!r.getEndTime().is_not_a_date_time());
        boost::this_thread::sleep(pt::seconds(1));
        r.endRent(nadt);
        BOOST_TEST(r.getEndTime() == end);
    }
    BOOST_AUTO_TEST_CASE(RentDaysTest){
        Rent r(testId, testClient, testVehicle, nadt);
        r.endRent(nadt);
        BOOST_TEST(r.getRentDays() == 0);
        pt::ptime test = pt::second_clock::local_time() + pt::minutes(1);
        r.endTime = test;
        BOOST_TEST(r.getRentDays() == 1);
        test = pt::second_clock::local_time() + pt::hours(23) + pt::minutes(59);
        r.endTime = test;
        BOOST_TEST(r.getRentDays() == 1);
        test = pt::second_clock::local_time() + pt::hours(24);
        r.endTime = test;
        BOOST_TEST(r.getRentDays() == 2);
    }
    BOOST_AUTO_TEST_CASE(RentCostZeroTest){
        Rent r(testId, testClient, testVehicle, nadt);
        r.endRent(nadt);
        BOOST_TEST(r.getRentCost() == 0);
    }
    BOOST_AUTO_TEST_CASE(RentCostNonZeroTest){
        Rent r(testId, testClient, testVehicle, nadt);
        r.beginTime = pt::second_clock::local_time() - pt::hours(24);
        r.endRent(nadt);
        BOOST_TEST(r.getRentCost() == r.getRentDays()*testVehicle->getBasePrice());
    }
    BOOST_AUTO_TEST_CASE(RentCostWithCarCostChangeTest){
        Rent r(testId, testClient, testVehicle, nadt);
        r.beginTime = pt::second_clock::local_time() - pt::hours(24);
        r.endRent(nadt);
        testVehicle->setBasePrice(150);
        BOOST_TEST(r.getRentCost() != r.getRentDays()*testVehicle->getBasePrice());
        BOOST_TEST(r.getRentCost() == r.rentCost);
    }
BOOST_AUTO_TEST_SUITE_END()