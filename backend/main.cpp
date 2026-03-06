#include "UrlShortener.h"
#include <iostream>

int main() {
    UrlShortener shortener;
    std::string longUrl = "https://www.example.com";
    std::string shortUrl = shortener.shorten(longUrl);
    std::cout << "Shortened: " << shortUrl << std::endl;
    std::cout << "Expanded: " << shortener.expand(shortUrl) << std::endl;
    return 0;
}
