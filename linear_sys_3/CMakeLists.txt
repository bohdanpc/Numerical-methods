cmake_minimum_required(VERSION 3.6)
project(lin_system)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(lin_system ${SOURCES})