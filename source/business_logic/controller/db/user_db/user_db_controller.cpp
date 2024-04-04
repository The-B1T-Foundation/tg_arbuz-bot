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


#include "user_db_controller.hpp"

// ---------------------------------------------------------------------------------------------------------------------
AUser_DB_Controller::AUser_DB_Controller(const AConfig& cfg) :
    Table_Name{ "user_data" },
    Connection_String{ std::format("host={} port={} dbname={} user={} password={}", cfg.Get_PG_Host(), cfg.Get_PG_Port(), cfg.Get_PG_DB_Name(), cfg.Get_PG_User(), cfg.Get_PG_Password()) }
{
    ALogger_Utility::Message(std::format("Connection string: {}", Connection_String));
}

// ---------------------------------------------------------------------------------------------------------------------
bool AUser_DB_Controller::Is_User_Exists(std::int64_t user_id)
{
    try
    {
        pqxx::connection connection{ Connection_String.c_str() };
        pqxx::work worker{ connection };

        pqxx::result response{ worker.exec(std::format(R"(SELECT COUNT(*) FROM {} WHERE id = '{}')", Table_Name, user_id)) };
        worker.commit();

        return response[0][0].as<std::int64_t>() != 0;
    }
    catch (const std::exception& ex)
    {
        ALogger_Utility::Error(ex.what());
    }

    return false;
}

// ---------------------------------------------------------------------------------------------------------------------
void AUser_DB_Controller::Create_User(const AUser& user)
{
    try
    {
        pqxx::connection connection{ Connection_String.c_str() };
        pqxx::work worker{ connection };

        worker.exec(std::format(R"(INSERT INTO {} (id, username, first_name) VALUES ('{}', '{}', '{}'))", Table_Name, user.Get_User_Id(), user.Get_User_Username(), user.Get_User_First_Name()));
        worker.commit();
    }
    catch (const std::exception& ex)
    {
        ALogger_Utility::Error(ex.what());
    }
}

// ---------------------------------------------------------------------------------------------------------------------
AUser AUser_DB_Controller::Get_User(std::int64_t user_id)
{
    try
    {
        pqxx::connection connection{ Connection_String.c_str() };
        pqxx::work worker{ connection };

        pqxx::result response{ worker.exec(std::format(R"(SELECT id, first_name, username FROM {} WHERE id = '{}')", Table_Name, user_id)) };
        worker.commit();

        return AUser{ response[0][0].as<std::int64_t>(), response[0][1].as<std::string>(), response[0][2].as<std::string>() };
    }
    catch (const std::exception& ex)
    {
        ALogger_Utility::Error(ex.what());
    }

    return AUser{};
}

// ---------------------------------------------------------------------------------------------------------------------
void AUser_DB_Controller::Update_User_Data(const AUser& user)
{
    try
    {
        pqxx::connection connection{ Connection_String.c_str() };
        pqxx::work worker{ connection };

        worker.exec(std::format(R"(UPDATE {} SET id = '{}', username = '{}', first_name = '{}')", Table_Name, user.Get_User_Id(), user.Get_User_Username(), user.Get_User_First_Name()));
        worker.commit();
    }
    catch (const std::exception& ex)
    {
        ALogger_Utility::Error(ex.what());
    }
}