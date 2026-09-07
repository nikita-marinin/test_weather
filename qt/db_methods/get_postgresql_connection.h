#ifndef GET_POSTGRESQL_CONNECTION_H
#define GET_POSTGRESQL_CONNECTION_H

sqlgen::Result<sqlgen::Ref<sqlgen::postgres::Connection>> getPostgresqlConnection();

#endif
