#include "message_handler.hpp"

// ---------------------------------------------------------------------------------------------------------------------
AMessage_Handler::AMessage_Handler(TgBot::Bot& tg_bot, ADB_Controller& db_controller) :
    TG_Bot(tg_bot), DB_Controller(db_controller)
{ }

// ---------------------------------------------------------------------------------------------------------------------
void AMessage_Handler::Handle_All_Messages(const TgBot::Message::Ptr& message)
{
    Auto_Register(message->from->id, message->from->username, message->from->firstName);

    if (message->text == SMessage_Commands::Start)
    {
        TG_Bot.getApi().sendMessage(message->chat->id, "Hello, Dear User");
    }
    else if (message->text == SMessage_Commands::Profile)
    {
        AUser current_user = DB_Controller.Get_User(message->from->id);
        TG_Bot.getApi().sendMessage(message->chat->id, "Info: " + std::to_string(current_user.Get_User_Id()) + " " + current_user.Get_User_First_Name() + " " + current_user.Get_User_Username());
    }
}

// ---------------------------------------------------------------------------------------------------------------------
void AMessage_Handler::Auto_Register(std::int64_t user_id, std::string_view username, std::string_view first_name)
{
    if (!DB_Controller.Is_User_Exists(user_id))
    {
        DB_Controller.Create_User(AUser(user_id, first_name.data(), username.data()));
    }
}