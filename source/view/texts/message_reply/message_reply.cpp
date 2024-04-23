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
    return std::format("Привіт, {} {}\nВітаємо тебе в нашому веселому Арбуз-боті{}!\nВіднині ти частина нашої спільноти{}!\nТут ти знайдеш безліч розваг, цікавих ігор та неймовірних пригод.\nГотуйся до захоплюючих вражень і незабутніх моментів!\nВеселощі та розваги чекають на тебе, так що насолоджуйся і грай з задоволенням {}!", username.data(), WAVING_HAND, WATERMELON, MEDAL, VIDEO_GAME);
}

// ---------------------------------------------------------------------------------------------------------------------
std::string AMessage_Reply::Get_Profile_Msg(const AUser& user, std::int64_t score)
{
    return std::format("Інформація про профіль арбуза{}\nНомер паспорту: {}\nІм'я у системі: {}\nРеальне ім'я: {}\nКількість насіннячка: {}", WATERMELON, user.Get_User_Id(), user.Get_User_Username(), user.Get_User_First_Name(), score);
}

// ---------------------------------------------------------------------------------------------------------------------
std::string AMessage_Reply::Get_Programmer_Game_Msg(const programmer_game::SExpression& expression)
{
    return std::format("Головний Арбуз вигенерував для тебе задачку з бінарним кодом:\n\n1-число:\t{}\n2-число:\t{}\nОперація яку слід примінити: {}\n\nВідповідь напиши за допомогою /answer (тут пробіл) відповідь", expression.First_Operand, expression.Second_Operand, expression.Operation);
}

// ---------------------------------------------------------------------------------------------------------------------
std::string AMessage_Reply::Get_Math_Game_Msg(const math_game::SMath_Expression& expression)
{
    return std::format("Головний Арбуз вигенерував для тебе математичну задачку:\n{}\n\nВідповідь напиши за допомогою /answer (тут пробіл) відповідь", expression.Expression);
}

// ---------------------------------------------------------------------------------------------------------------------
std::string AMessage_Reply::Get_Waiting_Time_Msg(std::int64_t time)
{
    return std::format("Стій ковбой, зачекай {}хв", time);
}

// ---------------------------------------------------------------------------------------------------------------------
std::string AMessage_Reply::Get_Correct_Answer_Msg(std::int64_t score)
{
    return std::format("Друже вітаю тебе, ти правильно вирішив цю задачу {}\nУ тебе виросло ще {} насіннячок.", CHECK_MARK_GREEN, score);
}

// ---------------------------------------------------------------------------------------------------------------------
std::string AMessage_Reply::Get_Incorrect_Answer_Msg(std::int64_t score, std::string_view correct_answer)
{
    return std::format("Нажаль ти не справився з вирішенням цієї задачи {}\nТому {} насіннячок зсохлося.\nПравильна відповідь це: {}", STOP_SIGN, score, correct_answer);
}

// ---------------------------------------------------------------------------------------------------------------------
std::string AMessage_Reply::Get_Help_Msg()
{
    return std::format("Привіт Арбуз, це блок з поясненням деяких ігрових механік {}\n\n1) Як відповідати на задачі ?\nВсе дуже просто пишеш команду /answer і через пробіл відповідь, наприклад: /answer 25\n\n2) Як вирішити гру pr_game, погугли про оператори &(AND) |(OR)\n\nЯкщо в тебе виникли проблеми, пиши власнику бота: https://t.me/hellowolrd36", DETAIL);
}