#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string to_two(int input) {
    int n = input;
    int m;
    string ret;
    while (n > 0) {
        n = input / 2;
        m = input % 2;
        ret += to_string(m);
        input = n;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<int> solution(string s) {
    vector<int> answer;
    int change{ 0 };
    int zero_cnt{ 0 };
    string input = s;

    while (input != "1") {
        sort(input.begin(), input.end(), [](const char& l, const char& r) {return l > r; });
        auto cur = find(input.begin(), input.end(), '0');
        int one = cur - input.begin();
        zero_cnt += input.end() - cur;
        change++;
        input = to_two(one);
    }
    return { change, zero_cnt };
}