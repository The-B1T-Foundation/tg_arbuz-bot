#pragma once

#include <string>
#include <cstdint>

class AUser
{
public:
    explicit AUser() = default;
    explicit AUser(std::int64_t user_id, std::string&& first_name, std::string&& username);

    ~AUser() = default;

    [[nodiscard]] std::int64_t Get_User_Id() const;
    [[nodiscard]] const std::string& Get_User_First_Name() const;
    [[nodiscard]] const std::string& Get_User_Username() const;

private:
    std::int64_t User_Id;
    std::string First_Name;
    std::string Username;
};