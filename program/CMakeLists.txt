cmake_minimum_required(VERSION 3.4)

project(Program)

set(SOURCE_FILES src/main.cpp)

add_executable(Program ${SOURCE_FILES})
find_package(Boost REQUIRED COMPONENTS thread)
target_link_libraries(Program Library Boost::thread)

target_include_directories(Program PUBLIC include)