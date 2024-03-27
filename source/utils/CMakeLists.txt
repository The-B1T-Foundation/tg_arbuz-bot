cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME UTILS)

set(HEADERS
        logger/logger_utility.hpp
)

set(SOURCES
        logger/logger_utility.cpp
)

add_library(${LIBRARY_NAME} STATIC ${HEADERS} ${SOURCES})

target_link_libraries(${LIBRARY_NAME} PUBLIC TG_ARBUZ_BOT_BUSINESS_LOGIC)
target_include_directories(${LIBRARY_NAME} PUBLIC ./)

include_directories(logger)