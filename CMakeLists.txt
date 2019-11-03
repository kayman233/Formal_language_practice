cmake_minimum_required(VERSION 3.10)
project(formal_lang_practice)

set(MAIN_SOURCE src/main.cpp)

# set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage") - попытки измерить code coverage
# set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

include_directories(includes/constants)
include_directories(includes/checkers)
add_subdirectory(includes/checkers)
include_directories(includes/reg_exp)
add_subdirectory(includes/reg_exp)
add_subdirectory(project_tests)
add_executable(analyse_reg_exp ${MAIN_SOURCE})

target_link_libraries(analyse_reg_exp RegExp)
target_link_libraries(analyse_reg_exp Checkers)




