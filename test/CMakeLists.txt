set(CMAKE_INCLUDE_CURRENT_DIR ON)
# include (SenderInstance.h)
set(CMAKE_AUTOMOC ON)
include_directories(../include /usr/include/qt5)
add_library(mtest SenderInstanceTest.cpp)