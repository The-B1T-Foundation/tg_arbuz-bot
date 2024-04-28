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
AMessage_Handler::AMessage_Handler(TgBot::Bot& tg_bot, AUser_DB_Controller& user_db_controller, AState_DB_Controller& state_db_controller, ATask_DB_Controller& task_db_controller, AStats_DB_Controller& stats_db_controller, AEnglish_Words_Info_API_Controller& english_words_api_controller) :
    TG_Bot{ tg_bot }, User_DB_Controller{ user_db_controller }, State_DB_Controller{ state_db_controller }, Task_DB_Controller{ task_db_controller }, Stats_DB_Controller{ stats_db_controller }, English_Words_API_Controller{ english_words_api_controller }
{ }

// ---------------------------------------------------------------------------------------------------------------------
void AMessage_Handler::Bind_Commands()
{
    TG_Bot.getEvents().onCommand(SMessage_Commands::Start.data(), [this](TgBot::Message::Ptr message) -> void
    {
        Auto_Register(message->from->id, message->from->username, message->from->firstName);
        TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Hello_Msg(message->from->username));
    });
    TG_Bot.getEvents().onCommand(SMessage_Commands::Profile.data(), [this](TgBot::Message::Ptr message) -> void
    {
        Auto_Register(message->from->id, message->from->username, message->from->firstName);

        auto user{ User_DB_Controller.Get_User(message->from->id) };
        auto score{ Stats_DB_Controller.Get_Score(message->from->id) };

        TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Profile_Msg(user, score));
    });
    TG_Bot.getEvents().onCommand(SMessage_Commands::Programmer_Game.data(), [this](TgBot::Message::Ptr message) -> void
    {
        Auto_Register(message->from->id, message->from->username, message->from->firstName);

        if (Can_Use_Command(message, Time_To_Wait))
        {
            auto expression{ AProgrammer_Game_Controller::Generate_Expression() };
            TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Programmer_Game_Msg(expression));

            State_DB_Controller.Set_State(message->from->id, AState_DB_Controller::EState_Type::Programmer_Game);
            Task_DB_Controller.Set_Answer(message->from->id, expression.Result);return;
        }
    });
    TG_Bot.getEvents().onCommand(SMessage_Commands::Math_Game.data(), [this](TgBot::Message::Ptr message) -> void
    {
        Auto_Register(message->from->id, message->from->username, message->from->firstName);

        if (Can_Use_Command(message, Time_To_Wait))
        {
            auto expression{ AMath_Problem_Game_Controller::Generate_Problem() };
            TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Math_Game_Msg(expression));

            State_DB_Controller.Set_State(message->from->id, AState_DB_Controller::EState_Type::Math_Game);
            Task_DB_Controller.Set_Answer(message->from->id, expression.Result);
        }
    });
    TG_Bot.getEvents().onCommand(SMessage_Commands::Answer.data(), [this](TgBot::Message::Ptr message) -> void
    {
        Handle_Answer(message);
    });
    TG_Bot.getEvents().onCommand(SMessage_Commands::Help.data(), [this](TgBot::Message::Ptr message) -> void
    {
        TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Help_Msg());
    });
    TG_Bot.getEvents().onCommand(SMessage_Commands::About_Project.data(), [this](TgBot::Message::Ptr message) -> void
    {
        TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Info_About_Project());
    });
    TG_Bot.getEvents().onCommand(SMessage_Commands::Definiton.data(), [this](TgBot::Message::Ptr message) -> void
    {
        Cut_User_Input(message->text, SMessage_Commands::Definiton.size());
        if (auto response{ English_Words_API_Controller.Get_Definition(message->text) }; response != std::nullopt)
        {
            TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Word_Definition(message->text, response.value()));
            return;
        }

        TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Not_Found_Word_Definition());
    });
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
bool AMessage_Handler::Can_Use_Command(const TgBot::Message::Ptr& message, std::int64_t required_difference)
{
    auto current_time{ static_cast<std::int64_t>(std::chrono::duration_cast<std::chrono::minutes>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) };
    if (auto difference{ current_time - Task_DB_Controller.Get_Time_Stamp(message->from->id) }; difference < required_difference)
    {
        TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Waiting_Time_Msg(required_difference - difference));
        return false;
    }

    Task_DB_Controller.Set_Time_Stamp(message->from->id, current_time);
    return true;
}

// ---------------------------------------------------------------------------------------------------------------------
void AMessage_Handler::Handle_Answer(TgBot::Message::Ptr& message)
{
    if (auto current_user_state{ State_DB_Controller.Get_State(message->from->id) }; current_user_state != AState_DB_Controller::EState_Type::Default)
    {
        std::int64_t score{};
        auto current_score{ Stats_DB_Controller.Get_Score(message->from->id) };

        switch (current_user_state)
        {
            case AState_DB_Controller::EState_Type::Programmer_Game:
            {
                score = AProgrammer_Game_Controller::Score;
                break;
            }
            case AState_DB_Controller::EState_Type::Math_Game:
            {
                score = AMath_Problem_Game_Controller::Score;
                break;
            }
        }

        auto answer{ Task_DB_Controller.Get_Answer(message->from->id) };
        Cut_User_Input(message->text, SMessage_Commands::Answer.size());

        if (answer != message->text)
        {
            Stats_DB_Controller.Set_Score(message->from->id, (current_score - score));
            TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Incorrect_Answer_Msg(score, answer));
        }
        else
        {
            Stats_DB_Controller.Set_Score(message->from->id, (current_score + score));
            TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Correct_Answer_Msg(score));
        }

        State_DB_Controller.Set_State(message->from->id, AState_DB_Controller::EState_Type::Default);
    }
}

// ---------------------------------------------------------------------------------------------------------------------
void AMessage_Handler::Cut_User_Input(std::string& input_text, std::size_t command_size)
{
    input_text.erase(input_text.begin(), input_text.begin() + static_cast<std::ptrdiff_t >(command_size + 1)); // erase /some_command part, + 1 for '/'
    input_text.erase(std::remove(input_text.begin(), input_text.end(), ' '), input_text.end());
}