cmake_minimum_required(VERSION 3.21)
project(options)

set(CMAKE_CXX_STANDARD 20)
#find_package(GTest REQUIRED)
#target_link_libraries(${PROJECT_NAME} GTest::gtest_main)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

find_package(GTest REQUIRED)
include_directories(${GTest_INCLUDE_DIRS})



add_executable(${PROJECT_NAME} main.cpp headers/OptionBase.hpp headers/Distributions.h headers/MonteCarloPricingEngine.h)
target_link_libraries(${PROJECT_NAME} GTest::gtest_main)
