cmake_minimum_required(VERSION 3.14)

project(tg_arbuz-bot LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra)

set(Boost_USE_MULTITHREADED ON)

add_subdirectory(libs)
add_subdirectory(source)