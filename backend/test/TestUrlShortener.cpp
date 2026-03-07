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

}

void test_repeat_shorten() {

}

void test_invalid_expand() {

}


int main() {
	test_shorten_and_expand();
	test_collision_handling();
	cout << "All tests passed." << endl;
	return 0;
}
