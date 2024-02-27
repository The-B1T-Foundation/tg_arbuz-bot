#include "config_utility.hpp"

std::optional<AConfig> AConfig_Utility::Load_Config()
{
    const char* tg_token = std::getenv("TG_TOKEN");
    if (!tg_token)
    {
        return std::nullopt;
    }

    const char* pg_host = std::getenv("PG_HOST");
    if (!pg_host)
    {
        return std::nullopt;
    }

    const char* pg_port = std::getenv("PG_PORT");
    if (!pg_port)
    {
        return std::nullopt;
    }

    const char* pg_db_name = std::getenv("PG_DB_NAME");
    if (!pg_db_name)
    {
        return std::nullopt;
    }

    const char* pg_user = std::getenv("PG_USER");
    if (!pg_user)
    {
        return std::nullopt;
    }

    const char* pg_password = std::getenv("PG_PASSWORD");
    if (!pg_password)
    {
        return std::nullopt;
    }

    return AConfig(tg_token, pg_host, pg_port, pg_db_name, pg_user, pg_password);
}