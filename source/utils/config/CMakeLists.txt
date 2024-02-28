cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME CONFIG_UTILITY)

set(HEADERS
    config_utility.hpp
)

set(SOURCES
    config_utility.cpp
)

add_library(${LIBRARY_NAME} STATIC ${HEADERS} ${SOURCES})
target_link_libraries(${LIBRARY_NAME}
        CONFIG_MODEL
)

target_include_directories(${LIBRARY_NAME} PUBLIC ./)