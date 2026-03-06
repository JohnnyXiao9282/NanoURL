#include "UrlShortener.h"
#include <random>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

constexpr size_t SHORT_URL_LENGTH = 6;

string UrlShortener::shorten(const string& longUrl) {
    if (longToShort.count(longUrl)) {
        return longToShort[longUrl];
    } else {
        hash<string> hasher;
        size_t hashValue = hasher(longUrl);
        stringstream ss;
        ss << hex << hashValue;
        string shortUrl = ss.str().substr(0, SHORT_URL_LENGTH);
    }
}

string UrlShortener::expand(const string& shortUrl) const {

}

string UrlShortener::generateShortUrl(const std::string& longUrl) {
    
}