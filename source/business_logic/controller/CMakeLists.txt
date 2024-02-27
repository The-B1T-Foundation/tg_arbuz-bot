cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME CONTROLLER)

add_library(${LIBRARY_NAME} INTERFACE)
target_link_libraries(${LIBRARY_NAME} INTERFACE
        DB_CONTROLLER
)

target_include_directories(${LIBRARY_NAME} INTERFACE ./)

add_subdirectory(db)