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

#include <utility>

#include <controller/db/base_db/base_db_controller.hpp>
#include <model/metrics/metrics_model.hpp>

class AMetrics_DB_Controller : public ABase_DB_Controller
{
public:
    explicit AMetrics_DB_Controller(const ADB_Config& db_cfg);
    ~AMetrics_DB_Controller() override = default;

    void Set_Metrics(const SMetrics& metrics);
    SMetrics Get_Metrics(std::int64_t metrics_id);

    // return min id and max id
    std::pair<std::int64_t, std::int64_t> Get_Metrics_Range();
    SMetrics Get_Best_Metrics();
};