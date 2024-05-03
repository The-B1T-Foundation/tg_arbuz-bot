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

#include <cstdint>
#include <chrono>
#include <ctime>
#include <iostream>

struct SMetrics
{
public:
    explicit SMetrics();
    [[maybe_unused]] explicit SMetrics(std::int64_t start_request_count, std::int64_t profile_request_count, std::int64_t pr_game_request_count, std::int64_t math_game_request_count, std::int64_t help_request_count, std::int64_t about_project_request_count, std::int64_t definition_request_count, std::string current_date);

    ~SMetrics() = default;

    void Set_Current_Date();
    [[nodiscard]] const std::string& Get_Current_Date() const;

    void Clear();

public:
    std::int64_t Start_Request_Count;
    std::int64_t Profile_Request_Count;
    std::int64_t Pr_Game_Request_Count;
    std::int64_t Math_Game_Request_Count;
    std::int64_t Help_Request_Count;
    std::int64_t About_Project_Request_Count;
    std::int64_t Definition_Request_Count;

private:
    std::string Current_Date;
};