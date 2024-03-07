#pragma once

#include <string>

class AConfig
{
public:
    explicit AConfig(std::string_view tg_token, std::string_view pg_host, std::string_view pg_port, std::string_view pg_db_name, std::string_view pg_user, std::string_view pg_password);
    ~AConfig() = default;

    [[nodiscard]] std::string_view Get_TG_Token() const;
    [[nodiscard]] std::string_view Get_PG_Host() const;
    [[nodiscard]] std::string_view Get_PG_Port() const;
    [[nodiscard]] std::string_view Get_PG_DB_Name() const;
    [[nodiscard]] std::string_view Get_PG_User() const;
    [[nodiscard]] std::string_view Get_PG_Password() const;

private:
    std::string_view TG_Token;
    std::string_view PG_Host;
    std::string_view PG_Port;
    std::string_view PG_DB_Name;
    std::string_view PG_User;
    std::string_view PG_Password;
};