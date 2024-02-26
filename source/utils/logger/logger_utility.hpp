#pragma once

#include <iostream>
#include <chrono>
#include <ctime>

class ALogger_Utility
{
public:
    ALogger_Utility() = default;
    ~ALogger_Utility() = default;

    static void Message(const std::string& message);
    static void Error(const std::string& error);
};