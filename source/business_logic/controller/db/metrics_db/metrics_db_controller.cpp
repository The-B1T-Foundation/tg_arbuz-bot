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


#include "metrics_db_controller.hpp"

// ---------------------------------------------------------------------------------------------------------------------
AMetrics_DB_Controller::AMetrics_DB_Controller(const ADB_Config& db_cfg) :
    ABase_DB_Controller{ db_cfg, "metrics_data" }
{ }

// ---------------------------------------------------------------------------------------------------------------------
void AMetrics_DB_Controller::Set_Metrics(const SMetrics& metrics)
{
    Exec_Query(std::format(R"(INSERT INTO {} (start_req, profile_req, pr_game_req, math_game_req, help_req, about_project_req, definition_req, date) VALUES ('{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}'))", Table_Name, metrics.Start_Request_Count, metrics.Profile_Request_Count, metrics.Pr_Game_Request_Count, metrics.Math_Game_Request_Count, metrics.Help_Request_Count, metrics.About_Project_Request_Count, metrics.Definition_Request_Count, metrics.Get_Current_Date()));
}

// ---------------------------------------------------------------------------------------------------------------------
SMetrics AMetrics_DB_Controller::Get_Metrics(std::int64_t metrics_id)
{
    auto response{ Exec_Query(std::format(R"(SELECT start_req, profile_req, pr_game_req, math_game_req, help_req, about_project_req, definition_req, date FROM {} WHERE id = '{}')", Table_Name, metrics_id)) };
    return SMetrics{ response[0][0].as<std::int64_t>(), response[0][1].as<std::int64_t>(), response[0][2].as<std::int64_t>(), response[0][3].as<std::int64_t>(), response[0][4].as<std::int64_t>(), response[0][5].as<std::int64_t>(), response[0][6].as<std::int64_t>(), response[0][7].as<std::string>() };
}

// ---------------------------------------------------------------------------------------------------------------------
std::int64_t AMetrics_DB_Controller::Get_Available_Metrics_Count()
{
    auto response{ Exec_Query(std::format(R"(SELECT MAX(id) FROM {})", Table_Name)) };
    return response[0][0].as<std::int64_t>();
}