#include "form.h"
#include "weather_info.h"
#include "day_weather.h"
#include "DataWorker.h"
#include "ParseWorker.h"

#include <QLabel>
#include <QString>
#include <QVBoxLayout>



Form::Form(QWidget *parent) : QWidget(parent){
    weatherInfo = nullptr;
    dayWeather = nullptr;
    mainLayout = new QVBoxLayout(this);
    dateLabel = new QLabel("Погода сейчас");    
    mainLayout->addWidget(dateLabel);
    setWindowTitle("Test Weather");

    dataWorker = new DataWorker(this);
    parseWorker = new ParseWorker(this);
    connect(dataWorker, &DataWorker::parseRequested,
            parseWorker, &ParseWorker::parseWeatherData);
    connect(parseWorker, &ParseWorker::dataParsed,
            dataWorker, &DataWorker::onWeatherDataParsed);
    dataWorker->requestParseWeatherData();
}

void Form::clearLayout(){
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

void Form::insertWeather(){
    clearLayout();
    weatherInfo = createWeatherInfoWidget();
    dayWeather = createDayWeatherWidget();
    mainLayout->insertWidget(1, weatherInfo);
    mainLayout->insertWidget(2, dayWeather);
}

