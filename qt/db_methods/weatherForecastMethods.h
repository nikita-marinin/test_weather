#ifndef WEATHER_FORECAST_METHODS_H
#define WEATHER_FORECAST_METHODS_H

#include "weatherForecast.h"

#include <vector>

std::vector<WeatherForecast> selectWeatherForecastByDate(sqlgen::Date date);

#endif
