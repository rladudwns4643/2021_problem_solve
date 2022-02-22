#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int, vector<int>> piv;
vector<int> solution(string s) {
    vector<int> answer;
    vector<int> t;
    vector < piv > vt;
    int size = s.size();
    int num = 0;
    for (int i = 1; i < size - 1; i++) {
        if (s[i] == '{') continue;
        if (s[i] == '}') {
            t.push_back(num);
            vt.push_back(make_pair(t.size(), t));
            num = 0;
            t.clear();
        }
        else if (s[i] == ',') {
            if (s[i - 1] == '}') continue;
            t.push_back(num);
            num = 0;
        }
        else {
            num *= 10;
            num += (s[i] - '0');
        }
    }

    sort(vt.begin(), vt.end());

    set<int> res;
    for (auto& p : vt) {
        for (int num : p.second) {
            if (res.find(num) == res.end()) {
                res.insert(num);
                answer.push_back(num);
            }
        }
    }


    return answer;
}
