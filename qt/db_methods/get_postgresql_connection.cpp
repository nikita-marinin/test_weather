#include <sqlgen/postgres.hpp>

auto getPostgresqlConnection(){
    
    const char* host = std::getenv("POSTGRES_HOST") ? std::getenv("POSTGRES_HOST") : "";
    const char* dbname = std::getenv("POSTGRES_DB") ? std::getenv("POSTGRES_DB") : "";
    const char* user = std::getenv("POSTGRES_USER") ? std::getenv("POSTGRES_USER") : "";
    const char* password = std::getenv("POSTGRES_PASSWORD") ? std::getenv("POSTGRES_PASSWORD") : "";
    const char* port = std::getenv("POSTGRES_PORT") ? std::getenv("POSTGRES_PORT") : "";
    
    auto credentials = sqlgen::postgres::Credentials{
        .user = user,
        .password = password,
        .host = host,
        .dbname = dbname,
        .port = port
    };

    auto conn = sqlgen::postgres::connect(credentials);
    return conn;
}

