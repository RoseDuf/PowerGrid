cmake_minimum_required(VERSION 2.6)
project(powergrid)

add_executable(powergrid main.cpp)

install(TARGETS powergrid RUNTIME DESTINATION bin)
