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
AMessage_Handler::AMessage_Handler(TgBot::Bot& tg_bot, AUser_DB_Controller& user_db_controller) :
        TG_Bot{ tg_bot }, User_DB_Controller{ user_db_controller }
{ }

// ---------------------------------------------------------------------------------------------------------------------
void AMessage_Handler::Handle_All_Messages(const TgBot::Message::Ptr& message)
{
    Auto_Register(message->from->id, message->from->username, message->from->firstName);

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
        AProgrammer_Game_Controller ctrl;
        programmer_game::SExpression expression{ ctrl.Generate_Expression() };
        TG_Bot.getApi().sendMessage(message->chat->id, std::format("{} {} {} = ?\nAnswer: {}", expression.First_Operand, expression.Operation, expression.Second_Operand, ctrl.Get_Correct_Result()));
    }
}

// ---------------------------------------------------------------------------------------------------------------------
void AMessage_Handler::Auto_Register(std::int64_t user_id, std::string_view username, std::string_view first_name)
{
    if (!User_DB_Controller.Is_User_Exists(user_id))
    {
        User_DB_Controller.Create_User(AUser(user_id, first_name.data(), username.data()));
    }
}