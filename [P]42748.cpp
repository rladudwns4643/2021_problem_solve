#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); ++i) {
        int& start = commands[i][0];
        int& end = commands[i][1];
        int& cur = commands[i][2];

        vector<int> t;
        t.reserve(50);
        t.assign(array.begin() + (start - 1), array.begin() + end);
        sort(t.begin(), t.end());
        answer.emplace_back(t[cur - 1]);
    }
    return answer;
}