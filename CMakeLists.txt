cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(cpp-cli-poc VERSION 0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

###############################################################################
##  Test code #################################################################
###############################################################################
enable_testing()
add_subdirectory(include/Catch2)
set (TEST_EXEC_NAME tests)
add_executable(${TEST_EXEC_NAME} test/test.cpp)
target_link_libraries(${TEST_EXEC_NAME} PRIVATE Catch2::Catch2)
add_test(TEST_ONE ${TEST_EXEC_NAME})

# set(MAIN_EXEC_NAME cpp-cli-poc)
# add_executable(${MAIN_EXEC_NAME} src/main.cpp)
