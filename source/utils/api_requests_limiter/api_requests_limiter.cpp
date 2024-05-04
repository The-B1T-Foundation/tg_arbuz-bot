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


#include "api_requests_limiter.hpp"


// ---------------------------------------------------------------------------------------------------------------------
AApi_Requests_Limiter::AApi_Requests_Limiter(std::ptrdiff_t requests_limit, std::int64_t required_duration) :
    Requests_Limit{ requests_limit }, Current_Requests_Count{ }, Required_Duration{ required_duration }, Previous_Time{ }
{ }

// ---------------------------------------------------------------------------------------------------------------------
bool AApi_Requests_Limiter::Can_Send_Request()
{
    auto current_time{ static_cast<std::int64_t>(std::chrono::duration_cast<std::chrono::hours>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) };
    if (current_time - Previous_Time >= Required_Duration && Requests_Limit - Current_Requests_Count > 1) // 1 - free requests
    {
        ++Current_Requests_Count;
        return true;
    }

    Previous_Time = current_time;
    Current_Requests_Count = 0;

    return false;
}

