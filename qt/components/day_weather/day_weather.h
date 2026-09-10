#ifndef DAY_WEATHER_H
#define DAY_WEATHER_H

#include "weatherForecast.h"

#include <QDateTime>
#include <QVector>

class QWidget;

QWidget* createDayWeatherWidget(const QVector<WeatherForecast>& weatherForecasts,
                                const QDateTime& currentDate);

#endif
