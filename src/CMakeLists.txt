include_directories(../include /usr/include/qt5)

qt5_wrap_cpp(SenderNetwork_SRC  ../include/SenderNetwork.h)
qt5_wrap_cpp(SenderInstance_SRC  ../include/SenderInstance.h)

add_executable(monitor ${SenderNetwork_SRC} ${SenderInstance_SRC} monitor.cpp SenderNetwork.cpp SenderBase.cpp SenderInstance.cpp HandlerBase.cpp)
target_link_libraries(monitor Qt5Core Qt5Network ${CMAKE_THREAD_LIBS_INIT})