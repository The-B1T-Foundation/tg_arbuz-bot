cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME DB_CONTROLLER)

set(HEADERS
        db_controller.hpp
)

set(SOURCES
        db_controller.cpp
)

add_library(${LIBRARY_NAME} STATIC ${HEADERS} ${SOURCES})
target_link_libraries(${LIBRARY_NAME} CONFIG_MODEL LOGGER_UTILITY POSTGRE_SQL USER_MODEL)

target_include_directories(${LIBRARY_NAME} PUBLIC ./)