cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME Arduino)
project(${PROJECT_NAME})

SCANDIR(LOCAL_LIBRARIES ${CMAKE_CURRENT_SOURCE_DIR}/libraries)
include_directories(${LOCAL_LIBRARIES})

set(${CMAKE_PROJECT_NAME}_BOARD uno)
set(${CMAKE_PROJECT_NAME}_PORT /dev/ttyACM0)

set(${CMAKE_PROJECT_NAME}_SKETCH Arduino.ino)
generate_arduino_firmware(${CMAKE_PROJECT_NAME})