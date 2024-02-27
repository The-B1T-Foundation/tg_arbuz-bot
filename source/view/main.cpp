#include <tgbot/tgbot.h>

#include <logger_utility.hpp>
#include <config_utility.hpp>
#include <message_handler.hpp>

int main()
{
    auto cfg = AConfig_Utility::Load_Config();

    if (cfg == std::nullopt)
    {
        ALogger_Utility::Error("Error reading config data");
        return -1;
    }

    TgBot::Bot tg_bot(cfg->Get_TG_Token());

    AMessage_Handler message_handler(tg_bot);
    tg_bot.getEvents().onAnyMessage([&message_handler](TgBot::Message::Ptr message) -> void
    {
        message_handler.Handle_All_Messages(message);
    });

    try
    {
        ALogger_Utility::Message(std::string("Bot username: ") + tg_bot.getApi().getMe()->username);
        TgBot::TgLongPoll long_poll(tg_bot);

        while(true)
        {
            ALogger_Utility::Message("Long poll started");
            long_poll.start();
        }
    }
    catch(TgBot::TgException& ex)
    {
        ALogger_Utility::Error(ex.what());
    }

    return 0;
}