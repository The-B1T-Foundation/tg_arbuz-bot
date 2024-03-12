cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME MESSAGE_REPLY)

set(HEADERS
        message_reply.hpp
)

set(SOURCES
        message_reply.cpp
)

add_library(${LIBRARY_NAME} STATIC ${HEADERS} ${SOURCES})
target_link_libraries(${LIBRARY_NAME} PUBLIC EMOJI)

target_include_directories(${LIBRARY_NAME} PUBLIC ./)