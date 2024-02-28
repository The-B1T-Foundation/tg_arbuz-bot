#pragma once

#include <tgbot/tgbot.h>
#include <db_controller.hpp>
#include <user_model.hpp>

class AMessage_Handler
{
public:
    explicit AMessage_Handler(TgBot::Bot& tg_bot, ADB_Controller& db_controller);
    ~AMessage_Handler() = default;

    void Handle_All_Messages(const TgBot::Message::Ptr& message);

private:
    TgBot::Bot& TG_Bot;
    ADB_Controller& DB_Controller;
};