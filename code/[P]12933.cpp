#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string s = to_string(n);
    sort(s.begin(), s.end(), [](const char& r, const char& l) {
        return r > l;
        });

    return atoll(s.c_str());
}

