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


#include "task_db_controller.hpp"

// ---------------------------------------------------------------------------------------------------------------------
ATask_DB_Controller::ATask_DB_Controller(const ADB_Config& db_cfg) :
    ABase_DB_Controller{ db_cfg, "task_data" }
{ }

// ---------------------------------------------------------------------------------------------------------------------
void ATask_DB_Controller::Create_Default_Task(std::int64_t user_id)
{
    Exec_Query(std::format(R"(INSERT INTO {} (id, answer) VALUES ('{}', '{}'))", Table_Name, user_id, ""));
}

// ---------------------------------------------------------------------------------------------------------------------
void ATask_DB_Controller::Set_Answer(std::int64_t user_id, std::string_view answer)
{
    Exec_Query(std::format(R"(UPDATE {} SET answer = '{}' WHERE id = '{}')", Table_Name, answer, user_id));
}

// ---------------------------------------------------------------------------------------------------------------------
std::string ATask_DB_Controller::Get_Answer(std::int64_t user_id)
{
    auto response{ Exec_Query(std::format(R"(SELECT answer FROM {} WHERE id = '{}')", Table_Name, user_id)) };
    return (*response)[0][0].as<std::string>();
}