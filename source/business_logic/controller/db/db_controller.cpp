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


#include "db_controller.hpp"

// ---------------------------------------------------------------------------------------------------------------------
ADB_Controller::ADB_Controller(const AConfig& cfg)
{
    Connection_String = std::string{ "host=" } + cfg.Get_PG_Host().data() + std::string{ " port=" } + cfg.Get_PG_Port().data() + std::string{ " dbname=" } + cfg.Get_PG_DB_Name().data() + std::string{ " user=" } + cfg.Get_PG_User().data() + std::string{ " password=" } + cfg.Get_PG_Password().data();
    ALogger_Utility::Message("Connection string: " + Connection_String);
}

// ---------------------------------------------------------------------------------------------------------------------
bool ADB_Controller::Is_User_Exists(std::int64_t user_id)
{
    try
    {
        pqxx::connection connection{ Connection_String.c_str() };
        pqxx::work worker{ connection };

        pqxx::result response{ worker.exec("SELECT COUNT(*) FROM user_data WHERE id = " + worker.quote(user_id)) };
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
void ADB_Controller::Create_User(const AUser& user)
{
    try
    {
        pqxx::connection connection{ Connection_String.c_str() };
        pqxx::work worker{ connection };

        worker.exec("INSERT INTO user_data (id, username, first_name) VALUES (" + worker.quote(user.Get_User_Id()) + ", " + worker.quote(user.Get_User_Username())+ ", " + worker.quote(user.Get_User_First_Name()) + ")");
        worker.commit();
    }
    catch (const std::exception& ex)
    {
        ALogger_Utility::Error(ex.what());
    }
}

// ---------------------------------------------------------------------------------------------------------------------
AUser ADB_Controller::Get_User(std::int64_t user_id)
{
    try
    {
        pqxx::connection connection{ Connection_String.c_str() };
        pqxx::work worker{ connection };

        pqxx::result response{ worker.exec("SELECT id, first_name, username FROM user_data WHERE id = " + worker.quote(user_id)) };
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
void ADB_Controller::Update_User_Data(const AUser& user)
{
    try
    {
        pqxx::connection connection{ Connection_String.c_str() };
        pqxx::work worker{ connection };

        worker.exec("UPDATE user_data SET id = " + worker.quote(user.Get_User_Id()) + ", username = " + worker.quote(user.Get_User_Username()) + ", first_name = " + worker.quote(user.Get_User_First_Name()));
        worker.commit();
    }
    catch (const std::exception& ex)
    {
        ALogger_Utility::Error(ex.what());
    }
}