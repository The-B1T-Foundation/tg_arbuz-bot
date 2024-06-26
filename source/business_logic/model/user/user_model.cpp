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


#include "user_model.hpp"

// ---------------------------------------------------------------------------------------------------------------------
AUser::AUser() :
    User_Id{}, First_Name{}, Username{}
{ }

// ---------------------------------------------------------------------------------------------------------------------
AUser::AUser(std::int64_t user_id, std::string first_name, std::string username) :
    User_Id{ user_id }, First_Name{ std::move(first_name) }, Username{ std::move(username) }
{ }

// ---------------------------------------------------------------------------------------------------------------------
std::int64_t AUser::Get_User_Id() const
{
    return User_Id;
}

// ---------------------------------------------------------------------------------------------------------------------
const std::string& AUser::Get_User_First_Name() const
{
    return First_Name;
}

// ---------------------------------------------------------------------------------------------------------------------
const std::string& AUser::Get_User_Username() const
{
    return Username;
}