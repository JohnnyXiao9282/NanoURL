#pragma once
#include "UrlShortener.h"
#include <unordered_map>
#include <string>

using namespace std;

class SimpleUrlShortener : public UrlShortener {
private:
    unordered_map<string, string> shortToLong;
    unordered_map<string, string> longToShort;
public:
    string shorten(const string& longUrl) override;
    string expand(const string& shortUrl) const override;
    string generateShortUrl(const string& longUrl) override;
};
