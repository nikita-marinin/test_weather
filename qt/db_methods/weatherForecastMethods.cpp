#include "weatherForecastMethods.h"
#include "get_postgresql_connection.h"

#include <sqlgen.hpp>
#include <sqlgen/postgres.hpp>

#include <QDebug>

std::vector<WeatherForecast> selectWeatherForecastByDate(sqlgen::Date date)
{
    using namespace sqlgen::literals;
    auto conn = getPostgresqlConnection();    
    const auto query = sqlgen::read<std::vector<WeatherForecast>> |
                       sqlgen::where("observation_date"_c == date);
                       
    auto result = query(conn); // Выполнение запроса
    return result.value();
}

void insertWeatherForecasts(const std::vector<WeatherForecast>& insertForecasts)
{
    auto conn = getPostgresqlConnection();
    auto result = sqlgen::insert(conn, insertForecasts);
}

void deleteWeatherForecastByDateTime(const std::vector<WeatherForecast>& deleteForecasts)
{
    using namespace sqlgen::literals;
    auto conn = getPostgresqlConnection();
    for (const auto& forecast : deleteForecasts) 
    {
        auto query = sqlgen::delete_from<WeatherForecast> | 
                     sqlgen::where("observation_date"_c == forecast.observation_date &&
                                   "observation_time"_c == forecast.observation_time); 
        query(conn); 
    }
}

std::vector<WeatherForecast> selectWeatherForecastByData(const WeatherForecast& checkWeatherForecast)
{
    using namespace sqlgen::literals;
    auto conn = getPostgresqlConnection();    
    const auto query = sqlgen::read<std::vector<WeatherForecast>> |
                       sqlgen::where("observation_date"_c == checkWeatherForecast.observation_date &&
                                     "observation_time"_c == checkWeatherForecast.observation_time &&
                                     "feels_like_C"_c == checkWeatherForecast.feels_like_C &&
                                     "temp_C"_c == checkWeatherForecast.temp_C &&
                                     "weather_description_ru"_c == checkWeatherForecast.weather_description_ru &&
                                     "visibility"_c == checkWeatherForecast.visibility &&
                                     "windspeed_kmph"_c == checkWeatherForecast.windspeed_kmph &&
                                     "wind_gust"_c == checkWeatherForecast.wind_gust &&
                                     "winddir_degree"_c == checkWeatherForecast.winddir_degree &&
                                     "precip_mm"_c == checkWeatherForecast.precip_mm &&
                                     "chance_of_rain"_c == checkWeatherForecast.chance_of_rain);
                                     
    auto result = query(conn);
    return result.value();
}