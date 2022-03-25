#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string t;
    vector<int> v;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            v.emplace_back(atoi(t.c_str()));
            t.clear();
        }
        else {
            t += s[i];
        }
    }
    v.emplace_back(atoi(t.c_str()));
    stable_sort(v.begin(), v.end(), [](const int& l, const int& r) {
        return l < r;
        });
    answer += to_string(v.front()) + " " + to_string(v.back());
    return answer;
}