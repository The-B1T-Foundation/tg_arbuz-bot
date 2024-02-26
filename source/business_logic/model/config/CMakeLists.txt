cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME CONFIG_MODEL)

set(HEADERS
        config_model.hpp
)

set(SOURCES
        config_model.cpp
)

add_library(${LIBRARY_NAME} STATIC ${HEADERS} ${SOURCES})
target_include_directories(${LIBRARY_NAME} PUBLIC ./)