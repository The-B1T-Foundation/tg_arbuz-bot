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


#include "programmer_game_controller.hpp"

// ---------------------------------------------------------------------------------------------------------------------
programmer_game::SExpression AProgrammer_Game_Controller::Generate_Expression()
{
    typedef std::bitset<UINT8_WIDTH> bitset;
    using namespace programmer_game;

    std::random_device rd{};
    std::mt19937 gen{ rd() };
    std::uniform_int_distribution<> distribution{ 0, 100 };

    auto first_operand{ static_cast<std::uint8_t>(distribution(gen)) };
    auto second_operand{ static_cast<std::uint8_t>(distribution(gen)) };

    if (distribution(gen) & 1)
    {
        Result_Expression = bitset(first_operand | second_operand).to_string();
        return SExpression{ bitset(first_operand).to_string(), bitset(second_operand).to_string(), "|" };
    }

    Result_Expression = bitset(first_operand & second_operand).to_string();
    return SExpression{ bitset(first_operand).to_string(), bitset(second_operand).to_string(), "&" };
}

// ---------------------------------------------------------------------------------------------------------------------
bool AProgrammer_Game_Controller::Check_Solution(std::string_view solution) const
{
    if (solution.size() != Result_Expression.size())
    {
        return false;
    }

    // TODO: .................................................................................................
    return (Result_Expression == solution);
    // return common_nasm_tools::Compare_String(Result_Expression.c_str(), solution.c_str(), solution.size());
}

// ---------------------------------------------------------------------------------------------------------------------
std::string_view AProgrammer_Game_Controller::Get_Correct_Result() const
{
    return Result_Expression;
}