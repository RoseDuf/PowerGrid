cmake_minimum_required(VERSION 2.6)
project(powergrid)

file(GLOB SOURCES
    *.h
    *.hpp
    *.cpp
)

add_executable(powergrid ${SOURCES})

install(TARGETS powergrid RUNTIME DESTINATION bin)
