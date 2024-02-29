#include "user_model.hpp"

AUser::AUser() :
    User_Id(0), First_Name(" "), Username(" ")
{ }

AUser::AUser(std::int64_t user_id, std::string&& first_name, std::string&& username) :
    User_Id(user_id), First_Name(first_name), Username(username)
{ }

std::int64_t AUser::Get_User_Id() const
{
    return User_Id;
}

const std::string& AUser::Get_User_First_Name() const
{
    return First_Name;
}

const std::string& AUser::Get_User_Username() const
{
    return Username;
}