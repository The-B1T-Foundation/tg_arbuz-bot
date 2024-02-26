cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME TG_ARBUZ_BOT_BUSINESS_LOGIC)

add_library(${LIBRARY_NAME} INTERFACE)
target_link_libraries(${LIBRARY_NAME} INTERFACE
        CONFIG_UTILITY
        CONFIG_MODEL
        LOGGER_UTILITY
)
target_include_directories(${LIBRARY_NAME} INTERFACE ./)

add_subdirectory(utils)
add_subdirectory(model)