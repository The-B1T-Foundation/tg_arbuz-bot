cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME UTILS)

add_library(${LIBRARY_NAME} INTERFACE)
target_link_libraries(${LIBRARY_NAME} INTERFACE
        CONFIG_UTILITY
        LOGGER_UTILITY
)
target_include_directories(${LIBRARY_NAME} INTERFACE .)

add_subdirectory(config)
add_subdirectory(logger)