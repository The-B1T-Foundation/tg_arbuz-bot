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

#include <string>
#include <cstdint>
#include <format>

#include <emoji.hpp>
#include <model/programmer_game/programmer_game_expression_model.hpp>
#include <model/user/user_model.hpp>

class AMessage_Reply
{
public:
    constexpr AMessage_Reply() = default;
    constexpr ~AMessage_Reply() = default;

    static std::string Get_Hello_Msg(std::string_view username);
    static std::string Get_Profile_Msg(const AUser& user, std::int64_t score);
    static std::string Get_Programmer_Game_Msg(programmer_game::SExpression& expression);
    static std::string Get_Waiting_Time_Msg(std::int64_t time);
    static std::string Get_Correct_Answer_Msg(std::int64_t score);
    static std::string Get_Incorrect_Answer_Msg(std::int64_t score, std::string_view correct_answer);
};