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


#include "logger_utility.hpp"

// ---------------------------------------------------------------------------------------------------------------------
void ALogger_Utility::Message(std::string_view message)
{
    const auto now{ std::chrono::system_clock::now() };
    const std::time_t t_c{ std::chrono::system_clock::to_time_t(now) };

    std::cout << "\033[1;32m|MESSAGE|\033[0m " << message << " \033[1;32m|Date ---> " << std::ctime(&t_c) << "\033[0m";
}

// ---------------------------------------------------------------------------------------------------------------------
void ALogger_Utility::Error(std::string_view error)
{
    const auto now{ std::chrono::system_clock::now() };
    const std::time_t t_c{ std::chrono::system_clock::to_time_t(now) };

    std::cout << "\033[1;31m|ERROR|\033[0m " << error << " \033[1;31m|Date ---> " << std::ctime(&t_c) << "\033[0m";
}