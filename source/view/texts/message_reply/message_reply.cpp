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


#include "message_reply.hpp"

// ---------------------------------------------------------------------------------------------------------------------
std::string AMessage_Reply::Get_Hello_Msg(std::string_view username)
{
    return std::format("Привіт, {} {}\nВітаємо тебе в нашому веселому Телеграм-боті!\nТут ти знайдеш безліч розваг, цікавих ігор та неймовірних пригод.\nГотуйся до захоплюючих вражень і незабутніх моментів!\nВеселощі та розваги чекають на тебе, так що насолоджуйся і грай з задоволенням {}!", username.data(), WAVING_HAND, VIDEO_GAME);
}

// ---------------------------------------------------------------------------------------------------------------------
std::string AMessage_Reply::Get_Profile_Msg(const AUser& user, std::int64_t score)
{
    return std::format("Profile info:\nID: {}\nUsername: {}\nName: {}\nScore: {}", user.Get_User_Id(), user.Get_User_Username(), user.Get_User_First_Name(), score);
}

// ---------------------------------------------------------------------------------------------------------------------
std::string AMessage_Reply::Get_Programmer_Game_Msg(programmer_game::SExpression& expression)
{
    return std::format("{}\n{}\n{}\nAnswer: ?", expression.First_Operand, expression.Operation, expression.Second_Operand);
}

// ---------------------------------------------------------------------------------------------------------------------
std::string AMessage_Reply::Get_Waiting_Time_Msg(std::int64_t time)
{
    return std::format("Please wait {} min", time);
}

// ---------------------------------------------------------------------------------------------------------------------
std::string AMessage_Reply::Get_Correct_Answer_Msg(std::int64_t score)
{
    return std::format("Correct answer: +{}", score);
}

// ---------------------------------------------------------------------------------------------------------------------
std::string AMessage_Reply::Get_Incorrect_Answer_Msg(std::int64_t score, std::string_view correct_answer)
{
    return std::format("Incorrect answer: -{}\nCorrect answer: {}", score, correct_answer);
}