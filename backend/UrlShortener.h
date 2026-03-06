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
    string shorten(const string& longUrl);
    string expand(const string& shortUrl) const;
};
