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
#include <utility>

#include <emoji.hpp>

#include <model/programmer_game/programmer_game_expression_model.hpp>
#include <model/math_problem_game/math_problem_game_expression_model.hpp>
#include <model/user/user_model.hpp>
#include <model/metrics/metrics_model.hpp>

class AMessage_Reply
{
public:
    constexpr AMessage_Reply() = default;
    constexpr ~AMessage_Reply() = default;

    static std::string Get_Hello_Msg(std::string_view username);
    static std::string Get_Profile_Msg(const AUser& user, std::int64_t score);
    static std::string Get_Programmer_Game_Msg(const programmer_game::SExpression& expression);
    static std::string Get_Math_Game_Msg(const math_game::SMath_Expression& expression);
    static std::string Get_Waiting_Time_Msg(std::int64_t time);
    static std::string Get_Correct_Answer_Msg(std::int64_t score);
    static std::string Get_Incorrect_Answer_Msg(std::int64_t score, std::string_view correct_answer);
    static std::string Get_Help_Msg();
    static std::string Get_Info_About_Project_Msg();
    static std::string Get_Word_Definition_Msg(std::string_view primary_word, std::string_view definiton);
    static std::string Get_Not_Found_Word_Definition_Msg();
    static std::string Get_Metrics_Range_Msg(const std::pair<std::int64_t, std::int64_t>& metrics_range);
    static std::string Get_Metrics_Msg(const SMetrics& metrics);
    static std::string Get_Limit_Api_Requests_Msg();
    static std::string Get_Antonym_Msg(std::string_view primary_word, std::string_view antonym);
    static std::string Get_Not_Found_Antonym_Msg();
    static std::string Get_Synonym_Msg(std::string_view primary_word, std::string_view synonym);
    static std::string Get_Not_Found_Synonym_Msg();
};