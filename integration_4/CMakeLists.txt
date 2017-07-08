cmake_minimum_required(VERSION 3.6)
project(integration)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(integration ${SOURCES})