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
AMessage_Handler::AMessage_Handler(TgBot::Bot& tg_bot, AUser_DB_Controller& user_db_controller, AState_DB_Controller& state_db_controller, ATask_DB_Controller& task_db_controller) :
        TG_Bot{ tg_bot }, User_DB_Controller{ user_db_controller }, State_DB_Controller{ state_db_controller }, Task_DB_Controller{ task_db_controller }
{ }

// ---------------------------------------------------------------------------------------------------------------------
void AMessage_Handler::Handle_All_Messages(const TgBot::Message::Ptr& message)
{
    Auto_Register(message->from->id, message->from->username, message->from->firstName);
    if (auto current_user_state{ State_DB_Controller.Get_State(message->from->id) }; current_user_state != AState_DB_Controller::EState_Type::Default)
    {
        Handle_State(message->from->id, current_user_state, message->text);
        return;
    }

    // --------------------------- Handle only commands ---------------------------
    if (message->text == SMessage_Commands::Start)
    {
        TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Hello_Msg(message->from->username));
    }
    else if (message->text == SMessage_Commands::Profile)
    {
        TG_Bot.getApi().sendMessage(message->chat->id, AMessage_Reply::Get_Profile_Msg(message->from->id));
    }
    else if (message->text == SMessage_Commands::Programmer_Game)
    {
        AProgrammer_Game_Controller ctrl{};
        auto expression{ ctrl.Generate_Expression() };

        TG_Bot.getApi().sendMessage(message->chat->id, std::format("{}\n{}\n{}\nAnswer: ?", expression.First_Operand, expression.Operation, expression.Second_Operand));
        State_DB_Controller.Set_State(message->from->id, AState_DB_Controller::EState_Type::Programmer_Game);
        Task_DB_Controller.Set_Answer(message->from->id, ctrl.Get_Correct_Result());
    }
}

// ---------------------------------------------------------------------------------------------------------------------
void AMessage_Handler::Auto_Register(std::int64_t user_id, std::string_view username, std::string_view first_name)
{
    if (!User_DB_Controller.Is_User_Exists(user_id))
    {
        User_DB_Controller.Create_User(AUser{ user_id, first_name.data(), username.data() });
        State_DB_Controller.Create_Default_State(user_id);
        Task_DB_Controller.Create_Default_Task(user_id);
    }
}

// ---------------------------------------------------------------------------------------------------------------------
void AMessage_Handler::Handle_State(std::int64_t user_id, AState_DB_Controller::EState_Type current_state, std::string_view message)
{
    switch (current_state)
    {
        case AState_DB_Controller::EState_Type::Programmer_Game:
        {
            if (auto answer{ Task_DB_Controller.Get_Answer(user_id) }; answer != message)
            {
                TG_Bot.getApi().sendMessage(user_id, std::format("Incorrect answer, correct answer -> {}", answer));
            }
            else
            {
                TG_Bot.getApi().sendMessage(user_id, "Correct Answer");
            }

            State_DB_Controller.Set_State(user_id, AState_DB_Controller::EState_Type::Default);
            break;
        }
    }
}