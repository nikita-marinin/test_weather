#include "parseMethods.h"
#include "httplib.h"

#include <string>

nlohmann::json parseData()
{
    httplib::Client cli("https://wttr.in");
    cli.set_connection_timeout(60, 0);
    cli.set_read_timeout(60, 0);

    const std::string path = "/смоленск?format=j1&lang=ru";
    auto res = cli.Get(path.c_str());
    if (!res) {
        nlohmann::json json;
        json["error"] = "Не удалось получить ответ от сервера";
        return json;
    }

    try {
        nlohmann::json json = nlohmann::json::parse(res->body);
        return json;
    } catch (const nlohmann::json::parse_error&) {
        nlohmann::json json;
        json["error"] = "Не удалось ответ преобразовать в json ответ от сервера";
        return json;
    }
}
