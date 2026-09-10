#include "weather_info.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

static QString toQString(const std::string& value)
{
    return QString::fromStdString(value);
}

static QString windArrow(int degree)
{
    const QString arrows[] = {"↓", "↙", "←", "↖", "↑", "↗", "→", "↘"};
    int index = ((degree % 360) + 360) % 360;
    return arrows[((index + 22) / 45) % 8];
}

static QString weatherImagePath(const QString& description)
{
    QString lower = description.toLower();
    if (lower.contains("дожд") || lower.contains("rain")) {
        return ":/images/rain.png";
    }
    if (lower.contains("ясно") || lower.contains("солн")) {
        return ":/images/sun.png";
    }
    return ":/images/cloud.png";
}

static QWidget* createTextWidget(const WeatherForecast& weatherForecast)
{
    QWidget* textWidget = new QWidget();
    QVBoxLayout* textLayout = new QVBoxLayout(textWidget);
    textLayout->setSpacing(4);

    QString description = toQString(weatherForecast.weather_description_ru);
    QString temp = toQString(weatherForecast.temp_C.value());
    QString feelsLike = toQString(weatherForecast.feels_like_C.value());
    QString windSpeed = toQString(weatherForecast.windspeed_kmph.value());
    QString windGust = toQString(weatherForecast.wind_gust.value());
    QString visibility = toQString(weatherForecast.visibility.value());
    QString precip = toQString(weatherForecast.precip_mm.value());
    QString chanceOfRain = toQString(weatherForecast.chance_of_rain.value());
    int windDegree = toQString(weatherForecast.winddir_degree.value()).toInt();

    QLabel* descriptionLabel = new QLabel(QString("<b>%1</b>").arg(description));
    QLabel* tempLabel = new QLabel(QString("<b>%1(%2) °C</b>").arg(temp, feelsLike));
    QLabel* windLabel = new QLabel(
        QString("<b>%1 %2-%3 км/ч</b>").arg(windArrow(windDegree), windSpeed, windGust));
    QLabel* visibilityLabel = new QLabel(QString("<b>%1 км</b>").arg(visibility));
    QLabel* precipLabel = new QLabel(
        QString("<b>%1 мм | %2%</b>").arg(precip, chanceOfRain));

    textLayout->addWidget(descriptionLabel);
    textLayout->addWidget(tempLabel);
    textLayout->addWidget(windLabel);
    textLayout->addWidget(visibilityLabel);
    textLayout->addWidget(precipLabel);

    return textWidget;
}

static QLabel* createImageLabel(const WeatherForecast& weatherForecast)
{
    QLabel* imageLabel = new QLabel();
    QString description = toQString(weatherForecast.weather_description_ru);
    QPixmap pixmap(weatherImagePath(description));
    imageLabel->setPixmap(
        pixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    return imageLabel;
}

QWidget* createWeatherInfoWidget(const WeatherForecast& weatherForecast)
{
    QWidget* weatherInfoWidget = new QWidget();
    QHBoxLayout* layout = new QHBoxLayout(weatherInfoWidget);
    layout->addWidget(createImageLabel(weatherForecast));
    layout->addWidget(createTextWidget(weatherForecast));
    layout->addStretch();
    return weatherInfoWidget;
}
