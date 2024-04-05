# MIT License

# Copyright (c) 2024 The B1T Foundation

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.


cmake_minimum_required(VERSION 3.14)

set(HEADERS
        texts/emoji/emoji.hpp
        texts/message_commands/message_commands.hpp
        handlers/message_handler/message_handler.hpp
        texts/message_reply/message_reply.hpp
)

set(SOURCES
        main.cpp

        texts/message_commands/message_commands.cpp
        handlers/message_handler/message_handler.cpp
        texts/message_reply/message_reply.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC TG_ARBUZ_BOT_BUSINESS_LOGIC TG_API)

include_directories(texts/emoji)
include_directories(texts/message_commands)
include_directories(handlers/message_handler)
include_directories(texts/message_reply)

