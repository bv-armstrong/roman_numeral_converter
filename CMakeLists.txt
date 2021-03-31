cmake_minimum_required(VERSION 3.17)
project(roman_numeral_converter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(roman_numeral_converter main.cpp RomanNumeralConverter.cpp)