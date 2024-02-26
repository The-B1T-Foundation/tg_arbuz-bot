#include "config_model.hpp"

AConfig::AConfig(std::string&& tg_token) :
    TG_Token(tg_token)
{ }

const std::string& AConfig::Get_TG_Token() const
{
    return TG_Token;
}