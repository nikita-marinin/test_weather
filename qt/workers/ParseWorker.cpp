#include <ParseWorker.h>
#include <parseMethods.h>


ParseWorker::ParseWorker(QObject *parent) 
    : QObject(parent) 
{
}

void ParseWorker::parseWeatherData()
{
    auto data = parseData();
    if (data.contains("error")) {
        emit parseError(QString::fromStdString(data["error"].get<std::string>()));
    } else {
        emit dataParsed(data);
    }
}