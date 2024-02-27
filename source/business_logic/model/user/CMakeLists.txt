cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME USER_MODEL)

set(HEADERS
        user_model.hpp
)

set(SOURCES
        user_model.cpp
)

add_library(${LIBRARY_NAME} STATIC ${HEADERS} ${SOURCES})
target_include_directories(${LIBRARY_NAME} PUBLIC ./)