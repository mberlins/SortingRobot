cmake_minimum_required(VERSION 3.16)
project(AALrobotBis)

set(CMAKE_CXX_STANDARD 14)

add_executable(AALrobotBis main.cpp Generator.h NaiveRobot.h SmartRobot.h SmartRobot.cpp NaiveRobot.cpp Generator.cpp SmartRobotBis.h SmartRobotBis.cpp)