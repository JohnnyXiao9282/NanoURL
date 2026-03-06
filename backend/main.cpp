#include "UrlShortener.h"
#include <iostream>

using namespace std;

int main() {
    UrlShortener shortener;
    string longUrl = "https://www.example.com";
    string shortUrl = shortener.shorten(longUrl);
    cout << "Shortened: " << shortUrl << endl;
    cout << "Expanded: " << shortener.expand(shortUrl) << endl;
    return 0;
}
