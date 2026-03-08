#include "../src/UrlShortener.h"
#include "../src/SimpleUrlShortener.h"
#include <iostream>
#include <cassert>

using namespace std;

void test_shorten_and_expand() {
    SimpleUrlShortener shortener;
    string longUrl = "https://www.example.com";
    string shortUrl = shortener.shorten(longUrl);
    assert(shortUrl.length() > 0);
    string expanded = shortener.expand(shortUrl);
    assert(expanded == longUrl);
    cout << "test_shorten_and_expand passed." << endl;
}

void test_collision_handling() {
    SimpleUrlShortener shortener;
    string url1 = "https://www.example.com/1";
    string url2 = "https://www.example.com/2";
    string short1 = shortener.shorten(url1);
    string short2 = shortener.shorten(url2);
    assert(short1 != short2);
    cout << "test_collision_handling passed." << endl;
}

void test_empty_url() {
    SimpleUrlShortener shortener;
    string emptyUrl = "";
    string shortUrl = shortener.shorten(emptyUrl);
    assert(shortUrl.length() > 0);
    string expanded = shortener.expand(shortUrl);
    assert(expanded == emptyUrl);
    cout << "test_empty_url passed." << endl;
}

void test_repeat_shorten() {
    SimpleUrlShortener shortener;
    string url = "https://www.repeat.com";
    string short1 = shortener.shorten(url);
    string short2 = shortener.shorten(url);
    assert(short1 == short2);
    string expanded = shortener.expand(short1);
    assert(expanded == url);
    cout << "test_repeat_shorten passed." << endl;
}

void test_invalid_expand() {
    SimpleUrlShortener shortener;
    string invalidShortUrl = "abcdef";
    string expanded = shortener.expand(invalidShortUrl);
    assert(expanded == "");
    cout << "test_invalid_expand passed." << endl;
}


int main() {
    test_shorten_and_expand();
    test_collision_handling();
    test_empty_url();
    test_repeat_shorten();
    test_invalid_expand();
    cout << "All tests passed." << endl;
    return 0;
}
