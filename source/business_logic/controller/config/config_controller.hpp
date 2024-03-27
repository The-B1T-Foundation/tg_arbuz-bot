#pragma once

#include <model/config/config_model.hpp>
#include <optional>

class AConfig_Controller
{
public:
    constexpr AConfig_Controller() = default;
    ~AConfig_Controller() = default;

    static std::optional<AConfig> Load_Config();
};