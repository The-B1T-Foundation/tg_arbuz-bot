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

set(LIBRARY_NAME TG_ARBUZ_BOT_BUSINESS_LOGIC)

set(MODEL_HEADERS
        model/user/user_model.hpp
        model/programmer_game/programmer_game_expression_model.hpp
        model/config/db_config/db_config_model.hpp
        model/config/tg_config/tg_config_model.hpp
        model/math_problem_game/math_problem_game_expression_model.hpp
        model/config/english_words_info_api_config/english_words_info_api_config_model.hpp
        model/metrics/metrics_model.hpp
        model/config/tg_root_user_config/tg_root_user_config_model.hpp
        model/config/meme_api_config/meme_api_config_model.hpp
)

set(MODEL_SOURCES
        model/user/user_model.cpp
        model/programmer_game/programmer_game_expression_model.cpp
        model/config/db_config/db_config_model.cpp
        model/config/tg_config/tg_config_model.cpp
        model/math_problem_game/math_problem_game_expression_model.cpp
        model/config/english_words_info_api_config/english_words_info_api_config_model.cpp
        model/metrics/metrics_model.cpp
        model/config/tg_root_user_config/tg_root_user_config_model.cpp
        model/config/meme_api_config/meme_api_config_model.cpp
)

set(CONTROLLER_HEADERS
        controller/db/user_db/user_db_controller.hpp
        controller/programmer_game/programmer_game_controller.hpp
        controller/db/state_db/state_db_controller.hpp
        controller/db/base_db/base_db_controller.hpp
        controller/config/db_config/db_config_controller.hpp
        controller/config/tg_config/tg_config_controller.hpp
        controller/db/task_db/task_db_controller.hpp
        controller/db/stats_db/stats_db_controller.hpp
        controller/math_problem_game/math_problem_game_controller.hpp
        controller/api/base_api/base_api_controller.hpp
        controller/api/english_words_info_api/english_words_info_api_controller.hpp
        controller/config/english_words_info_api_config/english_words_info_api_config_controller.hpp
        controller/db/metrics_db/metrics_db_controller.hpp
        controller/config/tg_root_user_config/tg_root_user_config_controller.hpp
        controller/api/meme_api/meme_api_controller.hpp
        controller/config/meme_api_config/meme_api_config_controller.hpp
)

set(CONTROLLER_SOURCES
        controller/db/user_db/user_db_controller.cpp
        controller/programmer_game/programmer_game_controller.cpp
        controller/db/state_db/state_db_controller.cpp
        controller/db/base_db/base_db_controller.cpp
        controller/config/db_config/db_config_controller.cpp
        controller/config/tg_config/tg_config_controller.cpp
        controller/db/task_db/task_db_controller.cpp
        controller/db/stats_db/stats_db_controller.cpp
        controller/math_problem_game/math_problem_game_controller.cpp
        controller/api/base_api/base_api_controller.cpp
        controller/api/english_words_info_api/english_words_info_api_controller.cpp
        controller/config/english_words_info_api_config/english_words_info_api_config_controller.cpp
        controller/db/metrics_db/metrics_db_controller.cpp
        controller/config/tg_root_user_config/tg_root_user_config_controller.cpp
        controller/api/meme_api/meme_api_controller.cpp
        controller/config/meme_api_config/meme_api_config_controller.cpp
)

add_library(${LIBRARY_NAME} STATIC
        ${MODEL_HEADERS}
        ${CONTROLLER_HEADERS}
        ${MODEL_SOURCES}
        ${CONTROLLER_SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC ./)
target_link_libraries(${LIBRARY_NAME} PUBLIC UTILS POSTGRE_SQL UTF8_USTRING JSON)

include_directories(model)
include_directories(controller)