cmake_minimum_required(VERSION 3.10)
project(formal_lang_practice)

set(SOURCE_LIB reg_exp.cpp)
add_library(RegExp SHARED ${SOURCE_LIB})