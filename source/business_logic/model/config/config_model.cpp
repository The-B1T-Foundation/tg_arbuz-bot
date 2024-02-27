#include "config_model.hpp"

AConfig::AConfig(std::string&& tg_token, std::string&& pg_host, std::string&& pg_port, std::string&& pg_db_name, std::string&& pg_user, std::string&& pg_password) :
    TG_Token(tg_token), PG_Host(pg_host), PG_Port(pg_port), PG_DB_Name(pg_db_name), PG_User(pg_user), PG_Password(pg_password)
{ }

const std::string& AConfig::Get_TG_Token() const
{
    return TG_Token;
}

const std::string& AConfig::Get_PG_Host() const
{
    return PG_Host;
}

const std::string& AConfig::Get_PG_Port() const
{
    return PG_Port;
}

const std::string& AConfig::Get_PG_DB_Name() const
{
    return PG_DB_Name;
}

const std::string& AConfig::Get_PG_User() const
{
    return PG_User;
}

const std::string& AConfig::Get_PG_Password() const
{
    return PG_Password;
}