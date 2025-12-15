cmake_minimum_required(VERSION 3.50)

project(CalculatorApp VERSION 1.0.0
					  DESCRIPTION "A powerful calculator with a beautiful gui"
					  LANGUAGES CXX)
add_executable(main src/main.cpp)
set_target_properties(main PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
