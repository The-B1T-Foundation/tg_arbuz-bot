// MIT License

// Copyright (c) 2024 The B1T Foundation

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#pragma once

#include <string>

class ADB_Config
{
public:
    explicit ADB_Config(std::string_view pg_host, std::string_view pg_port, std::string_view pg_db_name, std::string_view pg_user, std::string_view pg_password);
    constexpr ~ADB_Config() = default;

    [[nodiscard]] std::string_view Get_PG_Host() const;
    [[nodiscard]] std::string_view Get_PG_Port() const;
    [[nodiscard]] std::string_view Get_PG_DB_Name() const;
    [[nodiscard]] std::string_view Get_PG_User() const;
    [[nodiscard]] std::string_view Get_PG_Password() const;

private:
    std::string_view PG_Host;
    std::string_view PG_Port;
    std::string_view PG_DB_Name;
    std::string_view PG_User;
    std::string_view PG_Password;
};