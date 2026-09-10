#include "parseMethods.h"
#include "httplib.h"

#include <stdexcept>
#include <string>

nlohmann::json parseData()
{
    httplib::Client cli("https://wttr.in");
    cli.set_connection_timeout(60, 0);
    cli.set_read_timeout(60, 0);

    const std::string path = "/смоленск?format=j1&lang=ru";
    auto res = cli.Get(path.c_str());
    if (!res) {
        throw std::runtime_error("Не удалось получить ответ от сервера");
    }

    try {
        Json data = Json::parse(res->body);
        return data;
    } catch (const Json::parse_error&) {
        throw std::runtime_error("Не удалось ответ преобразовать в json ответ от сервера");
    }
}
