cmake_minimum_required(VERSION 3.16)

project(MyApplication LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MyApplication main.cpp
    mymath.h mymath.cpp)

include(GNUInstallDirs)
install(TARGETS MyApplication
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
