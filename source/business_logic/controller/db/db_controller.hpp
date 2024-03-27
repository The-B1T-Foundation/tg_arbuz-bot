#pragma once

#include <pqxx/pqxx>

#include <model/config/config_model.hpp>
#include <model/user/user_model.hpp>

#include <logger/logger_utility.hpp>


class ADB_Controller
{
public:
    explicit ADB_Controller(const AConfig& cfg);
    ~ADB_Controller() = default;

    bool Is_User_Exists(std::int64_t user_id);
    void Create_User(const AUser& user);
    AUser Get_User(std::int64_t user_id);
    void Update_User_Data(const AUser& user);

private:
    std::string Connection_String;
};