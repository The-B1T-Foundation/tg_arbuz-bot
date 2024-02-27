#pragma once

#include <string>

class AConfig
{
public:
    explicit AConfig(std::string&& tg_token);
    ~AConfig() = default;

    [[nodiscard]] const std::string& Get_TG_Token() const;

private:
    std::string TG_Token;
};