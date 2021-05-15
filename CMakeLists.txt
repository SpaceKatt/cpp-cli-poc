cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(cpp-cli-poc VERSION 0.1)

set(EXEC_NAME cpp-cli-poc)

###############################################################################
##  Test code #################################################################
###############################################################################
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/catch)
add_library(Catch2::Catch IMPORTED INTERFACE)
set_property(TARGET Catch2::Catch PROPERTY INTERFACE_INCLUDE_DIRECTORIES "${CATCH_INCLUDE_DIR}")
###############################################################################

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${EXEC_NAME} src/main.cpp)
