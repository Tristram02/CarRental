#include <boost/test/unit_test.hpp>
#include "model/Address.h"

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        Address a = Address("Warszawa", "Wolnosci", "22");
        BOOST_TEST(a.getCity() == "Warszawa");
        BOOST_TEST(a.getStreet() == "Wolnosci");
        BOOST_TEST(a.getNumber() == "22");
    }

//    BOOST_AUTO_TEST_CASE(SettersChangeTest){
//        Address a = Address("Warszawa", "Wolnosci", "22");
//        a.setCity("Szczecin");
//        a.setStreet("Pomorska");
//        a.setNumber("21");
//        BOOST_TEST(a.getCity() == "Szczecin");
//        BOOST_TEST(a.getStreet() == "Pomorska");
//        BOOST_TEST(a.getNumber() == "21");
//    }
//    BOOST_AUTO_TEST_CASE(SettersNotChangeTest){
//        Address a = Address("Warszawa", "Wolnosci", "22");
//        a.setCity("");
//        a.setStreet("");
//        a.setNumber("");
//        BOOST_TEST(a.getCity() == "Warszawa");
//        BOOST_TEST(a.getStreet() == "Wolnosci");
//        BOOST_TEST(a.getNumber() == "22");
//    }

BOOST_AUTO_TEST_SUITE_END()

