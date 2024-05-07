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


#include "metrics_model.hpp"

// ---------------------------------------------------------------------------------------------------------------------
SMetrics::SMetrics() :
    Start_Request_Count{}, Profile_Request_Count{}, Pr_Game_Request_Count{}, Math_Game_Request_Count{}, Help_Request_Count{}, About_Project_Request_Count{}, Definition_Request_Count{}, Antonym_Request_Count{}, Synonym_Request_Count{}, Meme_Request_Count{}, Current_Date{}
{ }

// ---------------------------------------------------------------------------------------------------------------------
SMetrics::SMetrics(std::int64_t start_request_count, std::int64_t profile_request_count, std::int64_t pr_game_request_count, std::int64_t math_game_request_count, std::int64_t help_request_count, std::int64_t about_project_request_count, std::int64_t definition_request_count, std::int64_t antonym_request_count, std::int64_t synonym_request_count, std::int64_t meme_request_count, std::string current_date) :
    Start_Request_Count{ start_request_count }, Profile_Request_Count{ profile_request_count }, Pr_Game_Request_Count{ pr_game_request_count }, Math_Game_Request_Count{ math_game_request_count }, Help_Request_Count{ help_request_count }, About_Project_Request_Count{ about_project_request_count }, Definition_Request_Count{ definition_request_count }, Antonym_Request_Count{ antonym_request_count }, Synonym_Request_Count{ synonym_request_count }, Meme_Request_Count{ meme_request_count },Current_Date{ std::move(current_date) }
{ }

// ---------------------------------------------------------------------------------------------------------------------
void SMetrics::Set_Current_Date()
{
    std::chrono::system_clock::time_point time_point{ std::chrono::system_clock::now() };
    Current_Date = std::format("{:%Y.%m.%d %H:%M}", time_point);
}

// ---------------------------------------------------------------------------------------------------------------------
const std::string& SMetrics::Get_Current_Date() const
{
    return Current_Date;
}

// ---------------------------------------------------------------------------------------------------------------------
std::int64_t SMetrics::Get_Total_Number_Of_Requests() const
{
    return Start_Request_Count + Profile_Request_Count + Pr_Game_Request_Count + Math_Game_Request_Count +  Help_Request_Count + About_Project_Request_Count + Definition_Request_Count + Antonym_Request_Count + Synonym_Request_Count + Meme_Request_Count;
}

// ---------------------------------------------------------------------------------------------------------------------
void SMetrics::Clear()
{
    Start_Request_Count = 0;
    Profile_Request_Count = 0;
    Pr_Game_Request_Count = 0;
    Math_Game_Request_Count = 0;
    Help_Request_Count = 0;
    About_Project_Request_Count = 0;
    Definition_Request_Count = 0;
    Antonym_Request_Count = 0;
    Synonym_Request_Count = 0;
    Meme_Request_Count = 0;
    Current_Date = " ";
}