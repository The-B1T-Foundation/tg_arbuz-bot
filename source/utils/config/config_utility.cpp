#include "config_utility.hpp"

std::optional<AConfig> AConfig_Utility::Load_Config()
{
    char* tg_token = std::getenv("TG_TOKEN");
    if (!tg_token)
    {
        return std::nullopt;
    }

    return AConfig(tg_token);
}