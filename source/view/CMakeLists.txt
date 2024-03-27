cmake_minimum_required(VERSION 3.14)

set(HEADERS
        emoji/emoji.hpp
        message_commands/message_commands.hpp
        message_handler/message_handler.hpp
        message_reply/message_reply.hpp
)

set(SOURCES
        main.cpp

        message_commands/message_commands.cpp
        message_handler/message_handler.cpp
        message_reply/message_reply.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC TG_ARBUZ_BOT_BUSINESS_LOGIC TG_API)

include_directories(emoji)
include_directories(message_commands)
include_directories(message_handler)
include_directories(message_reply)

