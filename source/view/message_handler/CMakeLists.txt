cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME MESSAGE_HANDLER)

set(HEADERS
        message_handler.hpp
)

set(SOURCES
        message_handler.cpp
)

add_library(${LIBRARY_NAME} STATIC ${HEADERS} ${SOURCES})
target_link_libraries(${LIBRARY_NAME}
        TG_API
)

target_include_directories(${LIBRARY_NAME} PUBLIC .)