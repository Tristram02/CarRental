cmake_minimum_required(VERSION 3.4)

project(Library)

set(SOURCE_FILES src/model/Client.cpp src/model/Address.cpp src/model/Vehicle.cpp src/model/Rent.cpp
        src/repositories/ClientRepository.cpp src/repositories/VehicleRepository.cpp src/repositories/RentRepository.cpp src/repositories/StorageContainer.cpp
        src/model/Bicycle.cpp src/model/MotorVehicle.cpp src/model/Moped.cpp src/model/Car.cpp
        src/model/ClientType.cpp src/model/Default.cpp src/model/Bronze.cpp src/model/Silver.cpp src/model/Gold.cpp src/model/Platinum.cpp src/model/Diamond.cpp
        src/managers/ClientManager.cpp src/managers/VehicleManager.cpp src/managers/RentManager.cpp)

add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES test/master.cpp test/ClientTest.cpp test/AddressTest.cpp test/VehicleTest.cpp test/RentTest.cpp test/StorageTest.cpp
        test/ClientManagerTest.cpp test/VehicleManagerTest.cpp test/RentManagerTest.cpp) # tu w przyszłości będą dodawane pliki źródłowe testów

add_executable (LibraryTest ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        Boost::thread)

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
