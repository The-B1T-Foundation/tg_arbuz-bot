#pragma once

#include <config_model.hpp>
#include <optional>

class AConfig_Utility
{
public:
    AConfig_Utility() = default;
    ~AConfig_Utility() = default;

    static std::optional<AConfig> Load_Config();
};