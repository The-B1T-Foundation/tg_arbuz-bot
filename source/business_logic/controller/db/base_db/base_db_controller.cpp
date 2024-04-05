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


#include "base_db_controller.hpp"

// ---------------------------------------------------------------------------------------------------------------------
ABase_DB_Controller::ABase_DB_Controller(const AConfig& cfg, std::string_view table_name) :
    Table_Name{ table_name },
    Connection_String{ std::format("host={} port={} dbname={} user={} password={}", cfg.Get_PG_Host(), cfg.Get_PG_Port(), cfg.Get_PG_DB_Name(), cfg.Get_PG_User(), cfg.Get_PG_Password()) }
{ }