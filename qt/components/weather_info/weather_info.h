#ifndef WEATHER_INFO_H
#define WEATHER_INFO_H

#include "weatherForecast.h"

class QWidget;

QWidget* createWeatherInfoWidget(const WeatherForecast& weatherForecast);

#endif
