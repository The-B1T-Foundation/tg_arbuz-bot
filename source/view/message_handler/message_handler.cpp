#include "message_handler.hpp"

AMessage_Handler::AMessage_Handler(TgBot::Bot& tg_bot) :
    TG_Bot(tg_bot)
{ }

void AMessage_Handler::Handle_All_Messages(const TgBot::Message::Ptr& message)
{
    if (message->text == "hello")
    {
        TG_Bot.getApi().sendMessage(message->chat->id, "hello bro!");
    }
}

