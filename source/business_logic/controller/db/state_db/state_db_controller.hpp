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

#include <pqxx/pqxx>

#include <controller/db/base_db/base_db_controller.hpp>
#include <logger/logger_utility.hpp>

class AState_DB_Controller : public ABase_DB_Controller
{
public:
    enum EState_Type : std::uint8_t
    {
        Default,
        Programmer_Game,
    };

public:
    explicit AState_DB_Controller(const AConfig& cfg);
    ~AState_DB_Controller() override = default;

    void Create_Default_State(std::int64_t user_id);

    void Set_State(std::int64_t user_id, EState_Type state_type);
    EState_Type Get_State(std::int64_t user_id);
};