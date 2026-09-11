#ifndef PARSEWORKER_H
#define PARSEWORKER_H

#include <QObject>
#include <QString>
#include <nlohmann/json.hpp>

class ParseWorker : public QObject
{
    Q_OBJECT
public:
    explicit ParseWorker(QObject *parent = nullptr);

public slots:
    void parseWeatherData();

signals:
    void dataParsed(const nlohmann::json& data);
    void parseError(const QString& error);
};

#endif
