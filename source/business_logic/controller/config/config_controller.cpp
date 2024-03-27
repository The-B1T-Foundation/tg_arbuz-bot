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


#include "config_controller.hpp"

// ---------------------------------------------------------------------------------------------------------------------
std::optional<AConfig> AConfig_Controller::Load_Config()
{
    const char* tg_token{ std::getenv("TG_TOKEN") };
    if (!tg_token)
    {
        return std::nullopt;
    }

    const char* pg_host{ std::getenv("POSTGRES_HOST") };
    if (!pg_host)
    {
        return std::nullopt;
    }

    const char* pg_port{ std::getenv("POSTGRES_PORT") };
    if (!pg_port)
    {
        return std::nullopt;
    }

    const char* pg_db_name{ std::getenv("POSTGRES_DB") };
    if (!pg_db_name)
    {
        return std::nullopt;
    }

    const char* pg_user{ std::getenv("POSTGRES_USER") };
    if (!pg_user)
    {
        return std::nullopt;
    }

    const char* pg_password{ std::getenv("POSTGRES_PASSWORD") };
    if (!pg_password)
    {
        return std::nullopt;
    }

    return AConfig{ tg_token, pg_host, pg_port, pg_db_name, pg_user, pg_password };
}