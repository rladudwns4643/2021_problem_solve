#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = INT64_MAX;
    int MAX = s.length();
    s += '/';
    for (int i = 1; i <= MAX; ++i) {
        int j = 0;
        int cnt = 1;
        string prev = "";
        string curr = "";
        string result;
        vector<pair<int, string>> v;
        while (j < s.length()) {
            if (j == 0) {
                prev = s.substr(0, i);
                j += i;
                continue;
            }
            curr = s.substr(j, i);
            if (prev == curr) ++cnt;
            else {
                v.push_back(make_pair(cnt, prev));
                prev = curr;
                cnt = 1;
            }
            j += i;
            if (j > s.length() - 1)v.push_back(make_pair(cnt, curr));
        }
        for (int j = 0; j < v.size(); ++j) {
            int data = v[j].first;
            string len = to_string(data);
            string str = v[j].second;
            if (data != 1) result += len;
            result += str;
        }
        if (answer > (result.length() - 1)) answer = result.length() - 1;
    }
    return answer;
}