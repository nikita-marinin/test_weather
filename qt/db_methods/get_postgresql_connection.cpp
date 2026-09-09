#include "get_postgresql_connection.h"

#include <cstdlib>
#include <string>

sqlgen::Result<sqlgen::Ref<sqlgen::postgres::Connection>> getPostgresqlConnection()
{
    const char* host = std::getenv("POSTGRES_HOST") ? std::getenv("POSTGRES_HOST") : "";
    const char* dbname = std::getenv("POSTGRES_DB") ? std::getenv("POSTGRES_DB") : "";
    const char* user = std::getenv("POSTGRES_USER") ? std::getenv("POSTGRES_USER") : "";
    const char* password = std::getenv("POSTGRES_PASSWORD") ? std::getenv("POSTGRES_PASSWORD") : "";

    int port = 5432;
    if (const char* port_str = std::getenv("POSTGRES_PORT"); port_str && *port_str) {
        port = std::stoi(port_str);
    }

    const auto credentials = sqlgen::postgres::Credentials{
        .user = user,
        .password = password,
        .host = host,
        .dbname = dbname,
        .port = port
    };

    return sqlgen::postgres::connect(credentials);
}
