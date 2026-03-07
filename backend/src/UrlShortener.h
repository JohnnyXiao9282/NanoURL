#pragma once
#include <string>

constexpr size_t SHORT_URL_LENGTH = 6;

using namespace std;

class UrlShortener {
public:
    virtual string shorten(const string& longUrl) = 0;
    virtual string expand(const string& shortUrl) const = 0;
    virtual string generateShortUrl(const string& longUrl) = 0;
    virtual ~UrlShortener() noexcept = default;
};
