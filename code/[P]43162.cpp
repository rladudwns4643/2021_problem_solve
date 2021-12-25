#include <string>
#include <vector>

using namespace std;

void dfs(int i, int n, vector<bool>& visit, vector<vector<int>>& computers) {
    for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        if (visit[j]) continue;
        if (computers[i][j] == 0) continue;
        visit[j] = true;
        dfs(j, n, visit, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> v(201, false);
    for (int i = 0; i < n; ++i) {
        if (v[i]) continue;
        ++answer;
        v[i] = true;
        dfs(i, n, v, computers);
    }
    return answer;
}