// MIT License

// Copyright (c) 2024 The B1T Foundation

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#pragma once

#include <thread>
#include <mutex>
#include <chrono>

#include <tgbot/tgbot.h>

#include <controller/db/user_db/user_db_controller.hpp>
#include <controller/db/state_db/state_db_controller.hpp>
#include <controller/db/task_db/task_db_controller.hpp>
#include <controller/db/stats_db/stats_db_controller.hpp>
#include <controller/db/metrics_db/metrics_db_controller.hpp>
#include <controller/api/english_words_info_api/english_words_info_api_controller.hpp>
#include <controller/programmer_game/programmer_game_controller.hpp>
#include <controller/math_problem_game/math_problem_game_controller.hpp>
#include <controller/api/meme_api/meme_api_controller.hpp>

#include <api_requests_limiter/api_requests_limiter.hpp>

#include <model/user/user_model.hpp>
#include <model/config/tg_root_user_config/tg_root_user_config_model.hpp>

#include <message_commands.hpp>
#include <message_reply.hpp>


class AMessage_Handler
{
public:
    explicit AMessage_Handler(TgBot::Bot& tg_bot, AUser_DB_Controller& user_db_controller, AState_DB_Controller& state_db_controller, ATask_DB_Controller& task_db_controller, AStats_DB_Controller& stats_db_controller, AMeme_API_Controller& meme_api_controller, AEnglish_Words_Info_API_Controller& english_words_api_controller, AMetrics_DB_Controller& metrics_db_controller, ATG_Root_User_Config& tg_root_user_cfg);
    constexpr ~AMessage_Handler() = default;

    void Bind_Commands();

    [[noreturn]] void Run_Metrics();

private:
    void Auto_Register(std::int64_t user_id, std::string_view username, std::string_view first_name);
    bool Can_Use_Command(const TgBot::Message::Ptr& message, std::int64_t required_difference);
    void Handle_Answer(TgBot::Message::Ptr& message);
    void Cut_User_Input(std::string& input_text, std::size_t command_size);
    bool Is_Root_User(std::int64_t user_id);

private:
    constexpr static std::size_t Time_To_Wait{ 1 };

private:
    static std::mutex Mutex;

    TgBot::Bot& TG_Bot;
    ATG_Root_User_Config& TG_Root_User_Cfg;
    SMetrics Metrics;

    AUser_DB_Controller& User_DB_Controller;
    AState_DB_Controller& State_DB_Controller;
    ATask_DB_Controller& Task_DB_Controller;
    AStats_DB_Controller& Stats_DB_Controller;
    AMetrics_DB_Controller& Metrics_DB_Controller;
    AEnglish_Words_Info_API_Controller& English_Words_API_Controller;
    AMeme_API_Controller& Meme_API_Controller;
    AApi_Requests_Limiter Words_Api_Requests_Limiter;
    AApi_Requests_Limiter Meme_Api_Requests_Limiter;
};