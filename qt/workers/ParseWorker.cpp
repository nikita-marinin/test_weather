#include <ParseWorker.h>
#include <parseMethods.h>


ParseWorker::ParseWorker(QObject *parent) 
    : QObject(parent) 
{
}

void ParseWorker::parseWeatherData()
{
    auto data = parseData();
    emit dataParsed(data);
}