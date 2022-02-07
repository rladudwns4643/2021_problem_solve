#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int t{ 0 };
    string s = to_string(x);
    for (auto& a : s) t += (a - '0');
    return x % t == 0 ? true : false;
}