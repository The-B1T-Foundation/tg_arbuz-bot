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

#include <format>
#include <stack>
#include <vector>
#include <string>
#include <optional>

#include <controller/api/base_api/base_api_controller.hpp>

#include <model/config/meme_api_config/meme_api_config_model.hpp>

class AMeme_API_Controller : public ABase_API_Controller
{
public:
    explicit AMeme_API_Controller(const AMeme_API_Config& meme_api_config);
    ~AMeme_API_Controller() override;

    std::optional<std::string> Get_Meme();

private:
    bool Send_Request(std::string_view request_type);

private:
    std::stack<std::string, std::vector<std::string>> Meme_Links_Stack;
    static nljson Json_Response;
    curl_slist* Headers;
};