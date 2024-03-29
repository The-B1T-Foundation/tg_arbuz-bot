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

#include <tgbot/tgbot.h>
#include <controller/db/db_controller.hpp>
#include <model/user/user_model.hpp>
#include <message_commands.hpp>
#include <message_reply.hpp>

class AMessage_Handler
{
public:
    explicit AMessage_Handler(TgBot::Bot& tg_bot, ADB_Controller& db_controller);
    ~AMessage_Handler() = default;

    void Handle_All_Messages(const TgBot::Message::Ptr& message);

private:
    void Auto_Register(std::int64_t user_id, std::string_view username, std::string_view first_name);

private:
    TgBot::Bot& TG_Bot;
    ADB_Controller& DB_Controller;
};