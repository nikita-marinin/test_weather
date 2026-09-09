#ifndef WEATHER_FORECAST_METHODS_H
#define WEATHER_FORECAST_METHODS_H

#include "weatherForecast.h"

#include <vector>

std::vector<WeatherForecast> selectWeatherForecastByDate(sqlgen::Date date);
void insertWeatherForecasts(const std::vector<WeatherForecast>& insertForecasts);
void deleteWeatherForecastByDateTime(const std::vector<WeatherForecast>& deleteForecasts);
std::vector<WeatherForecast> selectWeatherForecastByData(const WeatherForecast& checkWeatherForecast);

#endif
