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

struct SMessage_Commands
{
    constinit static std::string_view Start;
    constinit static std::string_view Profile;
    constinit static std::string_view Programmer_Game;
    constinit static std::string_view Math_Game;
    constinit static std::string_view Answer;
    constinit static std::string_view Help;
    constinit static std::string_view About_Project;
    constinit static std::string_view Definiton;
    constinit static std::string_view Metrics_Range;
    constinit static std::string_view Get_Metrics;
    constinit static std::string_view Get_Best_Metric;
    constinit static std::string_view Get_Antonym;
    constinit static std::string_view Get_Synonym;
    constinit static std::string_view Get_Meme;
};