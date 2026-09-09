#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class DataWorker;
class ParseWorker;

class Form : public QWidget
{
    Q_OBJECT

public:
    Form(QWidget *parent = nullptr);

private:
    void clearLayout();
    void insertWeather();

    QVBoxLayout* mainLayout;
    QWidget* dayWeather;
    QWidget* weatherInfo;
    QLabel* dateLabel;
    DataWorker* dataWorker;
    ParseWorker* parseWorker;
};

signals:
    void drowWeatherWidgets()

#endif
