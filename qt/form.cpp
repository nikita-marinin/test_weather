#include "form.h"
#include "weather_info.h"

#include <QVBoxLayout>

Form::Form(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(createWeatherInfoWidget());
    setWindowTitle("Test Weather");
    
}
