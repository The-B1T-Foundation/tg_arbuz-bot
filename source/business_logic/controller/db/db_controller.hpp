#pragma once

#include <pqxx/pqxx>

#include <config_model.hpp>
#include <logger_utility.hpp>
#include <user_model.hpp>

class ADB_Controller
{
public:
    explicit ADB_Controller(const AConfig& cfg);
    ~ADB_Controller() = default;

    bool Is_User_Exists(std::int64_t user_id);
    void Create_User(const AUser& user);

private:
    std::string Connection_String;
};