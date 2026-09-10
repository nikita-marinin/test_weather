#ifndef FORM_H
#define FORM_H

#include "weatherForecast.h"

#include <QDateTime>
#include <QLabel>
#include <QVector>
#include <QWidget>
#include <QVBoxLayout>

class DataWorker;
class ParseWorker;

class Form : public QWidget
{
    Q_OBJECT

public:
    Form(QWidget *parent = nullptr);

private:
    void clearLayout();
    void insertWeather(QVector<WeatherForecast> weatherForecasts);
    WeatherForecast getCurrentWeatherForecast(QVector<WeatherForecast>& weatherForecasts);
    static QVector<WeatherForecast> getDayWeatherForecasts(QVector<WeatherForecast>& weatherForecasts);

public slots:
    void drowWeatherWidgets(const QVector<WeatherForecast>& weatherForecasts);

private:
    QVBoxLayout* mainLayout;
    QWidget* dayWeather;
    QWidget* weatherInfo;
    QLabel* dateLabel;
    QDateTime currentDate;
    DataWorker* dataWorker;
    ParseWorker* parseWorker;
};

#endif
