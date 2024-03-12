#pragma once

#include <string>
#include <cstdint>

#include <emoji.hpp>

class AMessage_Reply
{
public:
    constexpr AMessage_Reply() = default;
    ~AMessage_Reply() = default;

    static std::string Get_Hello_Msg(std::string_view username);
    static std::string Get_Profile_Msg(std::int64_t user_id);
};