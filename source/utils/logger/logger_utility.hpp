#pragma once

#include <iostream>
#include <chrono>
#include <ctime>

class ALogger_Utility
{
public:
    constexpr ALogger_Utility() = default;
    ~ALogger_Utility() = default;

    static void Message(std::string_view message);
    static void Error(std::string_view error);
};