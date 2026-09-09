#ifndef GET_POSTGRESQL_CONNECTION_H
#define GET_POSTGRESQL_CONNECTION_H

#include <sqlgen/postgres.hpp>

sqlgen::Result<sqlgen::Ref<sqlgen::postgres::Connection>> getPostgresqlConnection();

#endif
