cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME MESSAGE_COMMANDS)

set(HEADERS
        message_commands.hpp
)

set(SOURCES
        message_commands.cpp
)

add_library(${LIBRARY_NAME} STATIC ${HEADERS} ${SOURCES})
target_include_directories(${LIBRARY_NAME} PUBLIC ./)