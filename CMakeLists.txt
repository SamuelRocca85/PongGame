cmake_minimum_required(VERSION 3.10)

project(pong)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(include)

