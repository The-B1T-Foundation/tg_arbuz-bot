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


#include "english_words_info_api_controller.hpp"

// ---------------------------------------------------------------------------------------------------------------------
nljson AEnglish_Words_Info_API_Controller::Json_Response{};

// ---------------------------------------------------------------------------------------------------------------------
AEnglish_Words_Info_API_Controller::AEnglish_Words_Info_API_Controller(const AEnglish_Words_Info_API_Config& english_words_info_api_config) :
    ABase_API_Controller{"https://wordsapiv1.p.rapidapi.com/words/" }, Headers{ nullptr }
{
    Headers = curl_slist_append(Headers, std::format("X-RapidAPI-Key: {}", english_words_info_api_config.Get_API_Key()).c_str());
    Headers = curl_slist_append(Headers, std::format("X-RapidAPI-Host: {}", english_words_info_api_config.Get_API_Host()).c_str());
}

// ---------------------------------------------------------------------------------------------------------------------
AEnglish_Words_Info_API_Controller::~AEnglish_Words_Info_API_Controller()
{
    curl_slist_free_all(Headers);
}

// ---------------------------------------------------------------------------------------------------------------------
std::optional<std::string> AEnglish_Words_Info_API_Controller::Get_Definition(const std::string& word)
{
    if (Curl = curl_easy_init(); Curl != nullptr)
    {
        curl_easy_setopt(Curl, CURLOPT_URL, (Url + word).data());
        curl_easy_setopt(Curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(Curl, CURLOPT_HTTPHEADER, Headers);
        curl_easy_setopt(Curl, CURLOPT_WRITEFUNCTION, &ABase_API_Controller::Write_Callback);
        curl_easy_setopt(Curl, CURLOPT_WRITEDATA, &AEnglish_Words_Info_API_Controller::Json_Response);

        curl_easy_perform(Curl);

        std::size_t resp_code{};
        curl_easy_getinfo(Curl, CURLINFO_RESPONSE_CODE, &resp_code);

        curl_easy_cleanup(Curl);

        if (resp_code != EHTTP_STATUS::OK || Json_Response["results"][0]["definition"].empty())
        {
            return std::nullopt;
        }
    }

    return Json_Response["results"][0]["definition"];
}