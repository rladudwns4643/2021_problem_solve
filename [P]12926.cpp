#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    int bound = 26 - n;
    for (auto& a : s) {
        if (a != ' ') {
            a += (a & 0x1F) <= bound ? n : -bound;
        }
    }
    return s;
}