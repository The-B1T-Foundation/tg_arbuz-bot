#include "message_handler.hpp"

AMessage_Handler::AMessage_Handler(TgBot::Bot& tg_bot, ADB_Controller& db_controller) :
    TG_Bot(tg_bot), DB_Controller(db_controller)
{ }

void AMessage_Handler::Handle_All_Messages(const TgBot::Message::Ptr& message)
{
    // For test
    if (message->text == "hello")
    {
        if (!DB_Controller.Is_User_Exists(message->from->id))
        {
            DB_Controller.Create_User(AUser(message->from->id, message->from->firstName.c_str(), message->from->username.c_str()));
            TG_Bot.getApi().sendMessage(message->chat->id, "You are unregistered!");

            return;
        }

        TG_Bot.getApi().sendMessage(message->chat->id, "You are registered!");
    }
    else if (message->text == "info")
    {
        AUser current_user = DB_Controller.Get_User(message->from->id);
        TG_Bot.getApi().sendMessage(message->chat->id, "Info: " + std::to_string(current_user.Get_User_Id()) + " " + current_user.Get_User_First_Name() + " " + current_user.Get_User_Username());
    }
    else if (message->text == "update")
    {
        DB_Controller.Update_User_Data(AUser(message->from->id, "test", "test"));
        TG_Bot.getApi().sendMessage(message->chat->id, "Successfully updated");
    }
}