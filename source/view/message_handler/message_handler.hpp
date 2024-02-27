#pragma once

#include <tgbot/tgbot.h>

class AMessage_Handler
{
public:
    explicit AMessage_Handler(TgBot::Bot& tg_bot);
    ~AMessage_Handler() = default;

    void Handle_All_Messages(const TgBot::Message::Ptr& message);

private:
    TgBot::Bot& TG_Bot;
};