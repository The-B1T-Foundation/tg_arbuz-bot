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


#include "meme_api_controller.hpp"

// ---------------------------------------------------------------------------------------------------------------------
nljson AMeme_API_Controller::Json_Response{};

// ---------------------------------------------------------------------------------------------------------------------
AMeme_API_Controller::AMeme_API_Controller(const AMeme_API_Config& meme_api_config) :
    ABase_API_Controller{ "https://programming-memes-images.p.rapidapi.com/v1/memes" }, Headers{ nullptr }
{
    Headers = curl_slist_append(Headers, std::format("X-RapidAPI-Key: {}", meme_api_config.Get_API_Key()).c_str());
    Headers = curl_slist_append(Headers, std::format("X-RapidAPI-Host: {}", meme_api_config.Get_API_Host()).c_str());
}

// ---------------------------------------------------------------------------------------------------------------------
AMeme_API_Controller::~AMeme_API_Controller()
{
    curl_slist_free_all(Headers);
}

// ---------------------------------------------------------------------------------------------------------------------
std::optional<std::string> AMeme_API_Controller::Get_Meme()
{
    if (Meme_Links_Stack.empty())
    {
        if (!Send_Request("GET"))
        {
            return std::nullopt;
        }

        for (std::size_t i{}; !Json_Response.empty() && i < 12; ++i) // 12 - default count of meme links
        {
            Meme_Links_Stack.push(Json_Response[i]["image"]);
        }
    }

    auto tmp{ Meme_Links_Stack.top() };
    Meme_Links_Stack.pop();

    return tmp;
}

// ---------------------------------------------------------------------------------------------------------------------
bool AMeme_API_Controller::Send_Request(std::string_view request_type)
{
    if (Curl = curl_easy_init(); Curl != nullptr)
    {
        curl_easy_setopt(Curl, CURLOPT_URL, Url.data());
        curl_easy_setopt(Curl, CURLOPT_CUSTOMREQUEST, request_type.data());
        curl_easy_setopt(Curl, CURLOPT_HTTPHEADER, Headers);
        curl_easy_setopt(Curl, CURLOPT_WRITEFUNCTION, &ABase_API_Controller::Write_Callback);
        curl_easy_setopt(Curl, CURLOPT_WRITEDATA, &AMeme_API_Controller::Json_Response);

        curl_easy_perform(Curl);

        std::size_t resp_code{};
        curl_easy_getinfo(Curl, CURLINFO_RESPONSE_CODE, &resp_code);

        curl_easy_cleanup(Curl);

        if (resp_code != EHTTP_STATUS::OK)
        {
            return false;
        }
    }

    return Curl != nullptr;
}