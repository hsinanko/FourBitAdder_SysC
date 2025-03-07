cmake_minimum_required(VERSION 3.10)

project(FirstSystemCProject)

# Set the SystemC include and library directories
set(SYSTEMC_INCLUDE_DIR $ENV{SYSTEMC_HOME}/include)
set(SYSTEMC_LIBRARY_DIR $ENV{SYSTEMC_HOME}/lib)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add this line, to enable compile command export
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the executable
add_executable(fourbitadder testbench.cc OneBitAdder.cc)

# Link against SystemC
target_include_directories(fourbitadder PRIVATE ${SYSTEMC_INCLUDE_DIR})
target_link_libraries(fourbitadder ${SYSTEMC_LIBRARY_DIR}/libsystemc.3.0.dylib)