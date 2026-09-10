#ifndef DATAWORKER_H
#define DATAWORKER_H

#include <QDate>
#include <QObject>
#include <QVector>
#include <nlohmann/json.hpp>

#include "weatherForecastMethods.h"
#include "weatherForecast.h"

class DataWorker : public QObject
{
    Q_OBJECT
public:
    explicit DataWorker(QObject *parent = nullptr);

public slots:
    void getDataByDate(QDate date);
    void requestParseWeatherData();
    void onWeatherDataParsed(const nlohmann::json& data);

signals:
    void dataReady(const QVector<WeatherForecast>& data);
    void parseRequested();
};

#endif