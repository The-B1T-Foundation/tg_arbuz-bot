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


#include <tgbot/tgbot.h>

#include <controller/config/db_config/db_config_controller.hpp>
#include <controller/config/tg_config/tg_config_controller.hpp>
#include <controller/config/english_words_info_api_config/english_words_info_api_config_controller.hpp>

#include <logger/logger_utility.hpp>
#include <message_handler.hpp>

int main()
{

#if 1
    auto tg_cfg{ ATG_Config_Controller::Load_Config() };
    if (tg_cfg == std::nullopt)
    {
        ALogger_Utility::Error("Error reading tg config data");
        return -1;
    }

    auto db_cfg{ ADB_Config_Controller::Load_Config() };
    if (db_cfg == std::nullopt)
    {
        ALogger_Utility::Error("Error reading db config data");
        return -1;
    }

    auto english_words_info_api_config{ AEnglish_Words_Info_API_Config_Controller::Load_Config() };
    if (english_words_info_api_config == std::nullopt)
    {
        ALogger_Utility::Error("Error reading english words api config data");
        return -1;
    }
#endif

    TgBot::Bot tg_bot{ tg_cfg->Get_TG_Token().data() };

    AUser_DB_Controller user_db_controller{ *db_cfg };
    AState_DB_Controller state_db_controller{ *db_cfg };
    ATask_DB_Controller task_db_controller{ *db_cfg };
    AStats_DB_Controller stats_db_controller{ *db_cfg };
    AEnglish_Words_Info_API_Controller english_words_api_controller{ *english_words_info_api_config };

    AMessage_Handler message_handler{ tg_bot, user_db_controller, state_db_controller, task_db_controller, stats_db_controller, english_words_api_controller };
    message_handler.Bind_Commands();

    try
    {
        TgBot::TgLongPoll long_poll{ tg_bot };

        while(true)
        {
            long_poll.start();
        }
    }
    catch(TgBot::TgException& ex)
    {
        ALogger_Utility::Error(ex.what());
    }

    return 0;
}