#pragma once
#include <string>
#include <unordered_map>

using namespace std;

class UrlShortener {
private:
    unordered_map<string, string> shortToLong;
    unordered_map<string, string> longToShort;
    string generateShortUrl(const string& longUrl);

public:
    virtual string shorten(const string& longUrl) = 0;
    virtual string expand(const string& shortUrl) const = 0;
    virtual string generateShortUrl(const string& longUrl) = 0;
    virtual ~UrlShortener() = default;
};
