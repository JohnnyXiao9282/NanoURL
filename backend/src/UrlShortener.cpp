#include "UrlShortener.h"
#include <random>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

#include "SimpleUrlShortener.h"

string SimpleUrlShortener::shorten(const string& longUrl) {
    if (longToShort.count(longUrl)) {
        return longToShort[longUrl];
    }
    string shortUrl = generateShortUrl(longUrl);
    shortToLong[shortUrl] = longUrl;
    longToShort[longUrl] = shortUrl;
    return shortUrl;
}

string SimpleUrlShortener::expand(const string& shortUrl) const {
    unordered_map<string, string>::const_iterator it = shortToLong.find(shortUrl);
    if (it != shortToLong.end()) {
        return it->second;
    }
    return "";
}

string SimpleUrlShortener::generateShortUrl(const string& longUrl) {
    hash<string> hasher;
    size_t hashValue = hasher(longUrl);
    stringstream ss;
    ss << hex << hashValue;
    string shortUrl = ss.str().substr(0, SHORT_URL_LENGTH);
    // Collision handling
    while (shortToLong.count(shortUrl)) {
        shortUrl += 'a';
    }
    return shortUrl;
}