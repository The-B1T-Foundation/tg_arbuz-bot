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


#include "message_handler.hpp"

// ---------------------------------------------------------------------------------------------------------------------
AMessage_Handler::AMessage_Handler(TgBot::Bot& tg_bot, AUser_DB_Controller& user_db_controller, AState_DB_Controller& state_db_controller, ATask_DB_Controller& task_db_controller, AStats_DB_Controller& stats_db_controller) :
        TG_Bot{ tg_bot }, User_DB_Controller{ user_db_controller }, State_DB_Controller{ state_db_controller }, Task_DB_Controller{ task_db_controller }, Stats_DB_Controller{ stats_db_controller }
{ }

// ---------------------------------------------------------------------------------------------------------------------
void AMessage_Handler::Handle_All_Messages(const TgBot::Message::Ptr& message)
{
    Auto_Register(message->from->id, message->from->username, message->from->firstName);
    if (auto current_user_state{ State_DB_Controller.Get_State(message->from->id) }; current_user_state != AState_DB_Controller::EState_Type::Default)
    {
        Handle_Game_State(message->from->id, current_user_state, message->text);
        return;
    }

    Handle_Default_Commands(message);
}

// ---------------------------------------------------------------------------------------------------------------------
void AMessage_Handler::Auto_Register(std::int64_t user_id, std::string_view username, std::string_view first_name)
{
    if (!User_DB_Controller.Is_User_Exists(user_id))
    {
        User_DB_Controller.Create_User(AUser{ user_id, first_name.data(), username.data() });
        State_DB_Controller.Create_Default_State(user_id);
        Task_DB_Controller.Create_Default_Task(user_id);
        Stats_DB_Controller.Create_Default_Stats(user_id);
    }
}

// ---------------------------------------------------------------------------------------------------------------------
void AMessage_Handler::Handle_Default_Commands(const TgBot::Message::Ptr& message)
{
    if (message->text == SMessage_Commands::Start)
    {
        TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Hello_Msg(message->from->username));
    }
    else if (message->text == SMessage_Commands::Profile)
    {
        auto user{ User_DB_Controller.Get_User(message->from->id) };
        auto score{ Stats_DB_Controller.Get_Score(message->from->id) };

        TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Profile_Msg(user, score));
    }
    else
    {
        Handle_Game_Commands(message);
    }
}

// ---------------------------------------------------------------------------------------------------------------------
void AMessage_Handler::Handle_Game_Commands(const TgBot::Message::Ptr& message)
{
    auto current_time{ static_cast<std::int64_t>(std::chrono::duration_cast<std::chrono::minutes>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) };
    if (auto difference{ current_time - Task_DB_Controller.Get_Time_Stamp(message->from->id) }; difference < 10) // 10 - waiting time
    {
        TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Waiting_Time_Msg(10 - difference));
        return;
    }

    if (message->text == SMessage_Commands::Programmer_Game)
    {
        auto expression{ AProgrammer_Game_Controller::Generate_Expression() };
        TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Programmer_Game_Msg(expression));

        State_DB_Controller.Set_State(message->from->id, AState_DB_Controller::EState_Type::Programmer_Game);
        Task_DB_Controller.Set_Answer(message->from->id, expression.Result);
    }

    Task_DB_Controller.Set_Time_Stamp(message->from->id, current_time);
}

// ---------------------------------------------------------------------------------------------------------------------
void AMessage_Handler::Handle_Game_State(std::int64_t user_id, AState_DB_Controller::EState_Type current_state, std::string_view message)
{
    auto current_score{ Stats_DB_Controller.Get_Score(user_id) };

    switch (current_state)
    {
        case AState_DB_Controller::EState_Type::Programmer_Game:
        {
            if (auto answer{ Task_DB_Controller.Get_Answer(user_id) }; answer != message)
            {
                Stats_DB_Controller.Set_Score(user_id, (current_score -= AProgrammer_Game_Controller::Score));
                TG_Bot.getApi().sendMessage(user_id, AMessage_Reply::Get_Incorrect_Answer_Msg(AProgrammer_Game_Controller::Score, answer));
            }
            else
            {
                Stats_DB_Controller.Set_Score(user_id, (current_score += AProgrammer_Game_Controller::Score));
                TG_Bot.getApi().sendMessage(user_id, AMessage_Reply::Get_Correct_Answer_Msg(AProgrammer_Game_Controller::Score));
            }

            break;
        }
    }

    State_DB_Controller.Set_State(user_id, AState_DB_Controller::EState_Type::Default);
}