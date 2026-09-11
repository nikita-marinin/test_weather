#include "form.h"
#include "weather_info.h"
#include "day_weather.h"
#include "DataWorker.h"
#include "ParseWorker.h"
#include "weatherForecast.h"
#include "InputDate.h"


#include <QLabel>
#include <QSizePolicy>
#include <QString>
#include <QStringList>
#include <QTime>
#include <QVBoxLayout>

Form::Form(QWidget *parent) : QWidget(parent){
    weatherInfo = nullptr;
    dayWeather = nullptr;
    currentDate = QDateTime::currentDateTime();
    mainLayout = new QVBoxLayout(this);
    dateLabel = new QLabel("Загрузка данных из БД");
    inputDate = new InputDate(this);
    errorLabel = nullptr;
    inputDate->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    mainLayout->insertWidget(0, dateLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(inputDate);
    setWindowTitle("Test Weather");

    dataWorker = new DataWorker(this);
    parseWorker = new ParseWorker(this);
    connect(dataWorker, &DataWorker::parseRequested,
            parseWorker, &ParseWorker::parseWeatherData);
    connect(parseWorker, &ParseWorker::dataParsed,
            dataWorker, &DataWorker::onWeatherDataParsed);
    connect(dataWorker, &DataWorker::dataReady,
            this, &Form::drowWeatherWidgets);
    connect(inputDate, &InputDate::inputDate,
            this, &Form::changeDate);
    connect(parseWorker, &ParseWorker::parseError,
            this, &Form::showError);

    dataWorker->requestParseWeatherData();
    dataWorker->getDataByDate(currentDate.date());
}

void Form::clearLayout(){
    if (dateLabel){
        mainLayout->removeWidget(dateLabel);
        delete dateLabel;
        dateLabel = nullptr;
    }
    if (weatherInfo){
        mainLayout->removeWidget(weatherInfo);
        delete weatherInfo;
        weatherInfo = nullptr;
    }
    if (dayWeather){
        mainLayout->removeWidget(dayWeather);
        delete dayWeather;
        dayWeather = nullptr;
    }
}

void Form::insertWeather(QVector<WeatherForecast> weatherForecasts){
    clearLayout();
    if (weatherForecasts.isEmpty()) {
        dateLabel = new QLabel("Нет данных в базе");
        mainLayout->insertWidget(0, dateLabel);
        return;
    }
    dayWeather = createDayWeatherWidget(getDayWeatherForecasts(weatherForecasts), currentDate);
    if (currentDate.date() == QDate::currentDate()) {
        dateLabel = new QLabel(QString("Погода сейчас"));
        mainLayout->insertWidget(0, dateLabel);
        weatherInfo = createWeatherInfoWidget(getCurrentWeatherForecast(weatherForecasts));
        mainLayout->insertWidget(1, weatherInfo);
        mainLayout->insertWidget(2, dayWeather);
    } else {
        mainLayout->insertWidget(0, dayWeather);
    }
}

void Form::drowWeatherWidgets(const QVector<WeatherForecast>& weatherForecasts)
{
    insertWeather(weatherForecasts);
}

WeatherForecast Form::getCurrentWeatherForecast(QVector<WeatherForecast>& weatherForecasts)
{
    int calculatedHour = (currentDate.time().hour() / 3) * 3;
    QString timeStr = QTime(calculatedHour, 0).toString("HH:mm:ss");

    for (WeatherForecast& forecast : weatherForecasts) {
        QString forecastTime = QString::fromStdString(forecast.observation_time.str());
        if (forecastTime == timeStr) {
            return forecast;
        }
    }

    return WeatherForecast{};
}

QVector<WeatherForecast> Form::getDayWeatherForecasts(QVector<WeatherForecast>& weatherForecasts)
{
    const QStringList times = {"00:00:00", "06:00:00", "12:00:00", "18:00:00"};
    QVector<WeatherForecast> result;
    for (int i = 0; i < times.size(); i++) {
        WeatherForecast found{};
        for (int j = 0; j < weatherForecasts.size(); j++) {
            QString forecastTime = QString::fromStdString(weatherForecasts[j].observation_time.str());
            if (forecastTime == times[i]) {
                found = weatherForecasts[j];
                break;
            }
        }
        result.append(found);
    }
    return result;
}

void Form::changeDate(const QDate& newDate)
{
    currentDate.setDate(newDate);
    dataWorker->getDataByDate(currentDate.date());
}

void Form::showError(const QString& error)
{
    if (errorLabel) {
        mainLayout->removeWidget(errorLabel);
        delete errorLabel;
        errorLabel = nullptr;
    }
    errorLabel = new QLabel("Не удалось спарсить сегодняшние данные по причине: " + error);
    int index = mainLayout->indexOf(inputDate);
    if (index < 0) {
        mainLayout->addWidget(errorLabel);
    } else {
        mainLayout->insertWidget(index, errorLabel);
    }
}