cmake_minimum_required(VERSION 3.10)
project(formal_lang_practice)

set(SOURCE_LIB checkers.cpp)
add_library(Checkers SHARED ${SOURCE_LIB})