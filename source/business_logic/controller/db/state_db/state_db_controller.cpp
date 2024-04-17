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


#include "state_db_controller.hpp"

// ---------------------------------------------------------------------------------------------------------------------
AState_DB_Controller::AState_DB_Controller(const ADB_Config& db_cfg) :
    ABase_DB_Controller{ db_cfg, "state_data" }
{ }

// ---------------------------------------------------------------------------------------------------------------------
void AState_DB_Controller::Create_Default_State(std::int64_t user_id)
{
    Exec_Query(std::format(R"(INSERT INTO {} (id, state) VALUES ('{}', '{}'))", Table_Name, user_id, static_cast<std::uint32_t>(EState_Type::Default)));
}

// ---------------------------------------------------------------------------------------------------------------------
void AState_DB_Controller::Set_State(std::int64_t user_id, EState_Type state_type)
{
    Exec_Query(std::format(R"(UPDATE {} SET state = '{}' WHERE id = '{}')", Table_Name, static_cast<std::uint32_t>(state_type), user_id));
}

// ---------------------------------------------------------------------------------------------------------------------
AState_DB_Controller::EState_Type AState_DB_Controller::Get_State(std::int64_t user_id)
{
    auto response{ Exec_Query(std::format(R"(SELECT state FROM {} WHERE id = '{}')", Table_Name, user_id)) };
    return static_cast<EState_Type>(response[0][0].as<std::uint32_t>());
}