#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> rate;
    double user = stages.size();

    for (int i = 1; i <= N; ++i) {
        double cnt = 0;
        for (int j = 0; j < stages.size(); ++j) {
            if (stages[j] == i) cnt++;
        }
        if (cnt == 0) rate.emplace_back(make_pair(0.0, i));
        else rate.emplace_back(make_pair((cnt / user), i));
        user -= cnt;
    }

    sort(rate.begin(), rate.end(), [](pair<double, int>& f, pair<double, int>& s) {
        if (f.first == s.first) return f.second < s.second;
        return f.first > s.first;
        });

    for (auto& a : rate) {
        answer.emplace_back(a.second);
    }

    return answer;
}

int main() {
    vector<int> a{ 2,1,2,6,2,4,3,3 };
    solution(5, a);
}