#pragma once

#include <string>

class AConfig
{
public:
    explicit AConfig(std::string&& tg_token, std::string&& pg_host, std::string&& pg_port, std::string&& pg_db_name, std::string&& pg_user, std::string&& pg_password);
    ~AConfig() = default;

    [[nodiscard]] const std::string& Get_TG_Token() const;
    [[nodiscard]] const std::string& Get_PG_Host() const;
    [[nodiscard]] const std::string& Get_PG_Port() const;
    [[nodiscard]] const std::string& Get_PG_DB_Name() const;
    [[nodiscard]] const std::string& Get_PG_User() const;
    [[nodiscard]] const std::string& Get_PG_Password() const;

private:
    std::string TG_Token;
    std::string PG_Host;
    std::string PG_Port;
    std::string PG_DB_Name;
    std::string PG_User;
    std::string PG_Password;
};