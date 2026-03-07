#include "UrlShortener.h"
#include <random>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;


constexpr size_t SHORT_URL_LENGTH = 6;

class SimpleUrlShortener : public UrlShortener {
private:
    unordered_map<string, string> shortToLong;
    unordered_map<string, string> longToShort;
    
public:
    string shorten(const string& longUrl) override {
        if (longToShort.count(longUrl)) {
            return longToShort[longUrl];
        }
        string shortUrl = generateShortUrl(longUrl);
        shortToLong[shortUrl] = longUrl;
        longToShort[longUrl] = shortUrl;
        return shortUrl;
    }

    string expand(const string& shortUrl) const override {
        unordered_map<string, string>:: const_iterator it = shortToLong.find(shortUrl);
        
        if (it != shortToLong.end()) {
            return it->second;
        }
        return "";
    }

    string generateShortUrl(const string& longUrl) override {
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
};