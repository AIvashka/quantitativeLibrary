cmake_minimum_required(VERSION 3.21)
project(options)

set(CMAKE_CXX_STANDARD 20)
#find_package(GTest REQUIRED)
#target_link_libraries(${PROJECT_NAME} GTest::gtest_main)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

find_package(GTest REQUIRED)
include_directories(${GTest_INCLUDE_DIRS})

file(GLOB INCLUDE_DIRS include)

add_executable(${PROJECT_NAME} main.cpp build/distributions.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} GTest::gtest_main)
