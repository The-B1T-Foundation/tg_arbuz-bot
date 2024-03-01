#pragma once

#include <tgbot/tgbot.h>
#include <db_controller.hpp>
#include <user_model.hpp>
#include <message_commands.hpp>

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