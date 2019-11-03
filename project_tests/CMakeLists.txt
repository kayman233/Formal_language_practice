cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(gtest_run checkers_tests.cpp reg_exp_tests.cpp)

target_link_libraries(gtest_run ${GTEST_LIBRARIES} pthread)
target_link_libraries(gtest_run RegExp)
target_link_libraries(gtest_run Checkers)