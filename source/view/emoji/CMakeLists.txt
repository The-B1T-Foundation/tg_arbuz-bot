cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME EMOJI)

add_library(${LIBRARY_NAME} INTERFACE emoji.hpp)
target_include_directories(${LIBRARY_NAME} INTERFACE ./)