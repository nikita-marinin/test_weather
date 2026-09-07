#include "weather_info.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QWidget>

static QWidget* createTextWidget(){
    QWidget* textWidget = new QWidget();
    QVBoxLayout* textLayout = new QVBoxLayout(textWidget);
    textLayout->setSpacing(4);

    QLabel* descriptionLabel = new QLabel("<b>Легкий дождь</b>");
    QLabel* tempLabel = new QLabel("<b>+10(8) °C</b>");
    QLabel* windLabel = new QLabel("<b>↘ 20-43 км/ч</b>");
    QLabel* visibilityLabel = new QLabel("<b>10 км</b>");
    QLabel* precipLabel = new QLabel("<b>0.1 мм | 35%</b>");

    textLayout->addWidget(descriptionLabel);
    textLayout->addWidget(tempLabel);
    textLayout->addWidget(windLabel);
    textLayout->addWidget(visibilityLabel);
    textLayout->addWidget(precipLabel);

    return textWidget;
}

static QLabel* createImageLabel(){
    QLabel* imageLabel = new QLabel();
    QPixmap pixmap(":/images/rain.png");
    imageLabel->setPixmap(
        pixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    return imageLabel;
}

QWidget* createWeatherInfoWidget(){
    QWidget* weatherInfoWidget = new QWidget();
    QHBoxLayout* layout = new QHBoxLayout(weatherInfoWidget);
    layout->addWidget(createImageLabel());
    layout->addWidget(createTextWidget());
    layout->addStretch();
    return weatherInfoWidget;
}
