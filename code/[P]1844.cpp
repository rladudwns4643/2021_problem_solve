#include<vector>
#include <queue>
using namespace std;

pair<int, int> dir[4] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
int visit[101][101] = { 0, };
int bfs(vector<vector<int>> m) {
    int w = m.size();
    int h = m[0].size();
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    visit[0][0] = 1;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        int cd = visit[cx][cy];
        q.pop();
        if (cx == w - 1 && cy == h - 1) return cd;
        for (int i = 0; i < 4; ++i) {
            int dx = cx + dir[i].first;
            int dy = cy + dir[i].second;
            if (dx < 0 || dx >= w || dy < 0 || dy >= h) continue;
            if (visit[dx][dy] != 0) continue;
            if (m[dx][dy] == 0) continue;
            q.push({ dx, dy });
            visit[dx][dy] = cd + 1;
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps) {
    return bfs(maps);
}