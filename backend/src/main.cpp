#include "UrlShortener.h"
#include "UrlShortener.cpp" // Ensure SimpleUrlShortener is visible
#include <iostream>

using namespace std;

int main() {
    UrlShortener* shortener = new SimpleUrlShortener();
    string longUrl = "https://www.example.com";
    string shortUrl = shortener->shorten(longUrl);
    cout << "Shortened: " << shortUrl << endl;
    cout << "Expanded: " << shortener->expand(shortUrl) << endl;
    delete shortener;
    return 0;
}
