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


#include "math_problem_game_controller.hpp"

// ---------------------------------------------------------------------------------------------------------------------
math_game::SMath_Expression AMath_Problem_Game_Controller::Generate_Problem()
{
    using namespace math_game;

    std::random_device rd{};
    std::mt19937 gen{ rd() };
    std::uniform_int_distribution<> distribution{ 0, 10 };

    const auto rnd_num{ static_cast<std::int32_t>(distribution(gen)) };
    const auto first_num{ static_cast<std::int32_t>(distribution(gen)) };
    const auto second_num{ static_cast<std::int32_t>(distribution(gen)) };
    const auto third_num{ static_cast<std::int32_t>(distribution(gen)) };

    // 1'st type of math problem: a + b * c
    if (rnd_num >= 0 && rnd_num < 3)
    {
        return SMath_Expression{std::format("{} + {} * {}", first_num, second_num, third_num), std::to_string(first_num + second_num * third_num) };
    }
    // 2'nd type of math problem: (a - b) * c
    else if (rnd_num >= 3 && rnd_num < 6)
    {
        return SMath_Expression{std::format("({} - {}) * {}", first_num, second_num, third_num), std::to_string((first_num - second_num) * third_num) };
    }

    // 3'd type of math problem: a * b - c
    return SMath_Expression{std::format("{} * {} - {}", first_num, second_num, third_num), std::to_string(first_num * second_num - third_num) };
}