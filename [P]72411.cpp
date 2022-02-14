#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> m;

void make_course(string original, string tmp, int idx, int size) {
    if (tmp.size() == size) m[tmp]++;

    for (int i = idx; i < original.size(); ++i) {
        make_course(original, tmp + original[i], i + 1, size);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < course.size(); ++i) {
        int size = course[i];
        m.clear();

        for (int j = 0; j < orders.size(); ++j) {
            sort(orders[j].begin(), orders[j].end());
            if (size <= orders[j].size()) {
                make_course(orders[j], "", 0, size);
            }
        }
        if (m.size() == 0) continue;
        vector<pair<string, int>>v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](const pair<string, int>& l, const pair<string, int>& r) {
            return l.second > r.second;
            });
        if (v[0].second >= 2) {
            for (int j = 0; j < v.size(); ++j) {
                if (v[0].second == v[j].second) {
                    answer.push_back(v[j].first);
                }
                else break;
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}