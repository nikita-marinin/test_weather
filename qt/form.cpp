#include "form.h"
#include "weather_info.h"
#include "day_weather.h"
#include "day_weather.h"

#include <QLabel>
#include <QString>
#include <QVBoxLayout>

Form::Form(QWidget *parent) : QWidget(parent){
    QVBoxLayout* layout = new QVBoxLayout(this);
    QLabel* dateLabel = new QLabel("Погода сейчас");
    layout->addWidget(dateLabel)
    layout->addWidget(createWeatherInfoWidget());
    layout->addWidget(createDayWeatherWidget());
    setWindowTitle("Test Weather");
}
