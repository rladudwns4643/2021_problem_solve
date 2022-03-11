#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<vector<int>> map;
bool visit[101];
int cnt = 0;

void dfs(int curr, int begin, int end) {
    cnt++;
    visit[curr] = true;
    for (int i = 0; i < map[curr].size(); ++i) {
        int next = map[curr][i];
        if ((begin == curr && next == end) || (end == curr && next == begin)) continue;
        if (!visit[next]) dfs(next, begin, end);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT32_MAX;
    map.resize(n + 1);

    for (const auto& a : wires) {
        map[a[0]].push_back(a[1]);
        map[a[1]].push_back(a[0]);
    }

    for (const auto& a : wires) {
        vector<int> cycles(2);
        int c = 0;
        fill(visit, visit + n + 1, false);
        for (int i = 1; i < n; ++i) {
            if (!visit[i]) {
                cnt = 0;
                dfs(i, a[0], a[1]);
                cycles[c] = cnt;
                ++c;
            }
        }
        answer = min(answer, abs(cycles[0] - cycles[1]));
    }

    return answer;
}