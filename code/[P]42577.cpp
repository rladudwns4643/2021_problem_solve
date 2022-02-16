#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    std::sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; ++i) {
        auto key = phone_book[i];
        auto next = phone_book[i + 1];

        if (key == next.substr(0, key.length())) return false;
    }
    return true;
}