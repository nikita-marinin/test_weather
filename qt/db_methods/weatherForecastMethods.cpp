#include "weatherForecastMethods.h"
#include "get_postgresql_connection.h"

#include <sqlgen.hpp>
#include <sqlgen/postgres.hpp>

std::vector<WeatherForecast> selectWeatherForecastByDate(sqlgen::Date date)
{
    using namespace sqlgen::literals;
    auto conn = getPostgresqlConnection();
    const auto query = sqlgen::read<std::vector<WeatherForecast>> |
                       sqlgen::where("observation_date"_c == date);
    auto result = query(conn);
    return result.value();
}

void insertWeatherForecastByDate(std::vector<WeatherForecast> forecastVector)
{
    using namespace sqlgen::literals;
    auto conn = getPostgresqlConnection();
    sqlgen::write(conn, forecastVector);
}