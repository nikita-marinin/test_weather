#include "day_weather.h"
#include "weather_info.h"
#include "weatherForecast.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QSizePolicy>
#include <QString>
#include <QStringList>
#include <QVBoxLayout>
#include <QWidget>

static QWidget* createDateWidget(const QDateTime& currentDate)
{
    QWidget* dateWidget = new QWidget();
    QHBoxLayout* dateLayout = new QHBoxLayout(dateWidget);
    QLabel* dateLabel = new QLabel(
        QString("<b>Погода за %1</b>").arg(currentDate.toString("dd.MM.yyyy")));
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

static QWidget* createWeatherListWidget(const QVector<WeatherForecast>& weatherForecasts)
{
    QWidget* weatherListWidget = new QWidget();
    QHBoxLayout* weatherListLayout = new QHBoxLayout(weatherListWidget);

    for (int i = 0; i < weatherForecasts.size(); i++) {
        QWidget* weatherInfo = createWeatherInfoWidget(weatherForecasts[i]);
        weatherInfo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        weatherListLayout->addWidget(weatherInfo);
    }

    return weatherListWidget;
}

QWidget* createDayWeatherWidget(const QVector<WeatherForecast>& weatherForecasts,
                                const QDateTime& currentDate)
{
    QWidget* dayWeatherWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(dayWeatherWidget);
    layout->addWidget(createDateWidget(currentDate));
    layout->addWidget(createDaysWidget());
    layout->addWidget(createWeatherListWidget(weatherForecasts));
    return dayWeatherWidget;
}
