cmake_minimum_required(VERSION 3.50)

set(CMAKE_CXX_STANDARD 17)
project(CalculatorApp VERSION 1.0.0
					  DESCRIPTION "A powerful calculator with a beautiful gui"
					  LANGUAGES CXX)
add_subdirectory(vendor)
add_subdirectory(src)
