# Add your source files here
add_executable(CalculatorApp
    main.cpp

)

# Link all libraries to your executable
target_link_libraries(CalculatorApp PRIVATE
    raylib
    imgui
    rlimgui
)

# Include directories (if needed)
target_include_directories(CalculatorApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
set_target_properties(CalculatorApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
