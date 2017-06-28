cmake_minimum_required(VERSION 3.6)
project(sinh)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(sinh ${SOURCES})