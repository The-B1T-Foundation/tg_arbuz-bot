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


#include "stats_db_controller.hpp"

// ---------------------------------------------------------------------------------------------------------------------
AStats_DB_Controller::AStats_DB_Controller(const ADB_Config& db_config) :
    ABase_DB_Controller{ db_config, "stats_data" }
{ }

// ---------------------------------------------------------------------------------------------------------------------
void AStats_DB_Controller::Create_Default_Stats(std::int64_t user_id)
{
    Exec_Query(std::format(R"(INSERT INTO {} (id, score) VALUES ('{}', '{}'))", Table_Name, user_id, 0));
}

// ---------------------------------------------------------------------------------------------------------------------
void AStats_DB_Controller::Set_Score(std::int64_t user_id, std::int64_t score)
{
    Exec_Query(std::format(R"(UPDATE {} SET score = '{}' WHERE id = '{}')", Table_Name, score, user_id));
}

// ---------------------------------------------------------------------------------------------------------------------
std::int64_t AStats_DB_Controller::Get_Score(std::int64_t user_id)
{
    auto response{ Exec_Query(std::format(R"(SELECT score FROM {} WHERE id = '{}')", Table_Name, user_id)) };
    return response[0][0].as<std::int64_t>();
}