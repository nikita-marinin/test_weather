#ifndef WEATHER_FORECAST_H
#define WEATHER_FORECAST_H

#include <string>
#include <cstdint>
#include <sqlgen.hpp>
#include <sqlgen/Varchar.hpp>
#include <rfl/Date.hpp>
#include <rfl/Time.hpp>

struct WeatherForecast {
    constexpr static const char* tablename = "weather_forecast";
    sqlgen::PrimaryKey<int32_t, sqlgen::auto_incr> id;
    rfl::Date observation_date;
    rfl::Time observation_time;
    sqlgen::Varchar<3> feels_like_C;
    sqlgen::Varchar<3> temp_C;
    std::string weather_description_ru;
    sqlgen::Varchar<2> visibility;
    sqlgen::Varchar<3> windspeed_kmph;
    sqlgen::Varchar<3> wind_gust;
    sqlgen::Varchar<3> winddir_degree;
    sqlgen::Varchar<3> precip_mm;
    sqlgen::Varchar<3> chance_of_rain;
};

#endif