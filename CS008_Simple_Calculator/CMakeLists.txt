cmake_minimum_required(VERSION 3.21)
project(CS8_Simple_Calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS8_Simple_Calculator main.cpp calcBase.cpp calcBase.h calcAdd.cpp calcAdd.h calcInputsENUMS.h calcArithmeticTypeENUMS.h calcHistory.cpp calcHistory.h)
