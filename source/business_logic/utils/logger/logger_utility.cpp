#include "logger_utility.hpp"

void ALogger_Utility::Message(const std::string& message)
{
    const auto now = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now);

    std::cout << "\033[1;32m|MESSAGE|\033[0m " << message << " \033[1;32m|Date ---> " << std::ctime(&t_c) << "\033[0m";
}

void ALogger_Utility::Error(const std::string& error)
{
    const auto now = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now);

    std::cout << "\033[1;31m|ERROR|\033[0m " << error << " \033[1;31m|Date ---> " << std::ctime(&t_c) << "\033[0m";
}