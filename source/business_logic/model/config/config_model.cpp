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


#include "config_model.hpp"

// ---------------------------------------------------------------------------------------------------------------------
AConfig::AConfig(std::string_view tg_token, std::string_view pg_host, std::string_view pg_port, std::string_view pg_db_name, std::string_view pg_user, std::string_view pg_password) :
    TG_Token{ tg_token }, PG_Host{ pg_host }, PG_Port{ pg_port }, PG_DB_Name{ pg_db_name }, PG_User{ pg_user }, PG_Password{ pg_password }
{ }

// ---------------------------------------------------------------------------------------------------------------------
std::string_view AConfig::Get_TG_Token() const
{
    return TG_Token;
}

// ---------------------------------------------------------------------------------------------------------------------
std::string_view AConfig::Get_PG_Host() const
{
    return PG_Host;
}

// ---------------------------------------------------------------------------------------------------------------------
std::string_view AConfig::Get_PG_Port() const
{
    return PG_Port;
}

// ---------------------------------------------------------------------------------------------------------------------
std::string_view AConfig::Get_PG_DB_Name() const
{
    return PG_DB_Name;
}

// ---------------------------------------------------------------------------------------------------------------------
std::string_view AConfig::Get_PG_User() const
{
    return PG_User;
}

// ---------------------------------------------------------------------------------------------------------------------
std::string_view AConfig::Get_PG_Password() const
{
    return PG_Password;
}