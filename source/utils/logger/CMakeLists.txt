cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME LOGGER_UTILITY)

set(HEADERS
        logger_utility.hpp
)

set(SOURCES
        logger_utility.cpp
)

add_library(${LIBRARY_NAME} STATIC ${HEADERS} ${SOURCES})
target_include_directories(${LIBRARY_NAME} PUBLIC ./)