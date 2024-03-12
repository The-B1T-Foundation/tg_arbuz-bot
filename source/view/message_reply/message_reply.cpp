#include "message_reply.hpp"

// ---------------------------------------------------------------------------------------------------------------------
std::string AMessage_Reply::Get_Hello_Msg(std::string_view username)
{
    char msg[1000] { };
    std::sprintf(msg, "Привіт, %s %s\nВітаємо тебе в нашому веселому Телеграм-боті!\nТут ти знайдеш безліч розваг, цікавих ігор та неймовірних пригод.\nГотуйся до захоплюючих вражень і незабутніх моментів!\nВеселощі та розваги чекають на тебе, так що насолоджуйся і грай з задоволенням %s!", username.data(), WAVING_HAND, VIDEO_GAME);

    return msg;
}

// ---------------------------------------------------------------------------------------------------------------------
std::string AMessage_Reply::Get_Profile_Msg(std::int64_t user_id)
{
    return "Тестові данні";
}