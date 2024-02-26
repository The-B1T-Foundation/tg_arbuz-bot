#include <tgbot/tgbot.h>

#include <logger_utility.hpp>
#include <config_utility.hpp>

int main()
{
    AConfig_Utility config_utility;
    auto cfg = config_utility.Load_Config();

    if (cfg == std::nullopt)
    {
        ALogger_Utility::Error("Error reading config data");
        return -1;
    }

    TgBot::Bot tg_bot(cfg->Get_TG_Token());

    tg_bot.getEvents().onCommand("start", [&tg_bot](TgBot::Message::Ptr message) -> void
    {
        tg_bot.getApi().sendMessage(message->chat->id, "Hi!");
        tg_bot.getApi().sendMessage(message->chat->id, message->text);
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