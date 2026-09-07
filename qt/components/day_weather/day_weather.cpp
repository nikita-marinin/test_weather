#include "day_weather.h"
#include "weather_info.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QSizePolicy>
#include <QStringList>
#include <QVBoxLayout>
#include <QWidget>

static QWidget* createDateWidget()
{
    QWidget* dateWidget = new QWidget();
    QHBoxLayout* dateLayout = new QHBoxLayout(dateWidget);
    QLabel* dateLabel = new QLabel("<b>07.09.2026</b>");
    dateLayout->addWidget(dateLabel);
    return dateWidget;
}

static QWidget* createDaysWidget()
{
    QWidget* daysWidget = new QWidget();
    QHBoxLayout* daysLayout = new QHBoxLayout(daysWidget);

    const QStringList dayTime = {"Утро", "День", "Вечер", "Ночь"};
    for (int i = 0; i < dayTime.size(); i++) {
        QLabel* dayLabel = new QLabel(QString("<b>%1</b>").arg(dayTime[i]));
        dayLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        daysLayout->addWidget(dayLabel);
    }

    return daysWidget;
}

static QWidget* createWeatherListWidget()
{
    QWidget* weatherListWidget = new QWidget();
    QHBoxLayout* weatherListLayout = new QHBoxLayout(weatherListWidget);

    for (int i = 0; i < 4; i++) {
        QWidget* weatherInfo = createWeatherInfoWidget();
        weatherInfo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        weatherListLayout->addWidget(weatherInfo);
    }

    return weatherListWidget;
}

QWidget* createDayWeatherWidget()
{
    QWidget* dayWeatherWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(dayWeatherWidget);
    layout->addWidget(createDateWidget());
    layout->addWidget(createDaysWidget());
    layout->addWidget(createWeatherListWidget());
    return dayWeatherWidget;
}
