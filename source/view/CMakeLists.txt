cmake_minimum_required(VERSION 3.14)

set(SOURCES
        main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME}
        TG_API
        POSTGRE_SQL
        TG_ARBUZ_BOT_BUSINESS_LOGIC
        UTILS
        MESSAGE_HANDLER
)

add_subdirectory(message_handler)
add_subdirectory(message_commands)