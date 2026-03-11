#include "UrlShortener.h"
#include "SimpleUrlShortener.h"
#include "httplib.h"
#include "nlohmann/json.hpp"
#include <iostream>

using namespace httplib;
using json = nlohmann::json;

int main() {
    Server svr;
    SimpleUrlShortener shortener;

    // CORS preflight handler
    svr.Options(R"(.*)", [](const httplib::Request&, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "POST, GET, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
    });

    svr.Post("/api/shorten", [&](const Request& req, Response& res) {
        try {
            auto j = json::parse(req.body);
            std::string longUrl = j["url"];
            std::string shortUrl = shortener.shorten(longUrl);
            json resp = { {"shortUrl", shortUrl} };
            res.set_content(resp.dump(), "application/json");
            res.set_header("Access-Control-Allow-Origin", "*");
        } catch (...) {
            res.status = 400;
            res.set_content("{\"error\":\"Invalid request\"}", "application/json");
            res.set_header("Access-Control-Allow-Origin", "*");
        }
    });

    std::cout << "Server running on http://localhost:8080" << std::endl;
    svr.listen("0.0.0.0", 8080);
    return 0;
}
