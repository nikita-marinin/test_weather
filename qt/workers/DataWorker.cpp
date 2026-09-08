#include "DataWorker.h"
#include "weatherForecast.h"

#include <QDebug>

#include <format>
#include <string>

DataWorker::DataWorker(QObject *parent) 
    : QObject(parent) 
{
}

void DataWorker::getDataByDate(sqlgen::Date date)
{
    auto records = selectWeatherForecastByDate(date);
    QVector<WeatherForecast> data(records.begin(), records.end());
    emit dataReady(data);
}

void DataWorker::requestParseWeatherData()
{
    emit parseRequested();
}

static std::string jsonTimeToForecastTime(const nlohmann::json& jsonTime)
{
    int hours = std::stoi(jsonTime.get<std::string>()) / 100;
    return std::format("{:02d}:00:00", hours);
}

static QVector<WeatherForecast> toWeatherForecastFromJson(const nlohmann::json& data){
    QVector<WeatherForecast> weatherForecastVector;
    std::string date = data["weather"][0]["date"].get<std::string>();
    for (int i = 0; i < data["weather"][0]["hourly"].size(); i++) {
        auto hourly = data["weather"][0]["hourly"][i];
        std::string time = jsonTimeToForecastTime(hourly["time"]);
        WeatherForecast forecast{
            .observation_date = sqlgen::Date(date),
            .observation_time = sqlgen::Timestamp<"%H:%M:%S">(time),
            .feels_like_C = hourly["FeelsLikeC"].get<std::string>(),
            .temp_C = hourly["FeelsLikeC"].get<std::string>(),
            .weather_description_ru = hourly["lang_ru"][0]["value"].get<std::string>(),
            .visibility = hourly["visibility"].get<std::string>(),
            .windspeed_kmph = hourly["windspeedKmph"].get<std::string>(),
            .wind_gust = hourly["WindGustKmph"].get<std::string>(),
            .winddir_degree = hourly["winddirDegree"].get<std::string>(),
            .precip_mm = hourly["precipMM"].get<std::string>(),
            .chance_of_rain = hourly["chanceofrain"].get<std::string>(),
        };
        weatherForecastVector.append(forecast);
    }
    return weatherForecastVector;
}

static void toWeatherForecastFromJsonItem(const nlohmann::json& data)
{
    qDebug().noquote() << QString::fromStdString(data.dump(4));
} 

void DataWorker::onWeatherDataParsed(const nlohmann::json& data)
{
    toWeatherForecastFromJson(data);
}
