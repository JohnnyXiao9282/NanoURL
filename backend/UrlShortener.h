#pragma once
#include <string>
#include <unordered_map>

class UrlShortener {
public:
    std::string shorten(const std::string& longUrl);
    std::string expand(const std::string& shortUrl) const;
private:
    std::unordered_map<std::string, std::string> shortToLong;
    std::unordered_map<std::string, std::string> longToShort;
    std::string generateShortUrl(const std::string& longUrl);
};
