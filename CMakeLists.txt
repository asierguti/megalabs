cmake_minimum_required(VERSION 2.8.11)

project(monitoring)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# include (SenderInstance.h)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "-fPIC -std=c++14 -Wall -pedantic")
find_package (Threads)
find_package(Qt5 COMPONENTS Core Network)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

subdirs(src test)
