#include "db_controller.hpp"

// "host=localhost port=5432 dbname=test user=postgres password=123456789"
ADB_Controller::ADB_Controller(const AConfig& cfg)
{
    Connection_String = "host=" + cfg.Get_PG_Host() + " port=" + cfg.Get_PG_Port() + " dbname=" + cfg.Get_PG_DB_Name() + " user=" + cfg.Get_PG_User() + " password=" + cfg.Get_PG_Password();
    ALogger_Utility::Message("Connection string: " + Connection_String);
}

bool ADB_Controller::Is_User_Exists(std::int64_t user_id)
{
    try
    {
        pqxx::connection connection(Connection_String.c_str());
        pqxx::work worker(connection);

        pqxx::result response = worker.exec("SELECT COUNT(*) FROM user_data WHERE id = " + worker.quote(user_id));
        worker.commit();

        return response[0][0].as<std::int64_t>() != 0;
    }
    catch (const std::exception& ex)
    {
        ALogger_Utility::Error(ex.what());
    }

    return false;
}