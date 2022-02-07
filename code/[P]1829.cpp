#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,-1,0,1 };
bool visit[100][100] = { 0, };

int bfs(int sy, int sx, int m, int n, vector<vector<int>> picture) {
    int color = picture[sy][sx];
    int size = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    visit[sy][sx] = 1;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
            if (visit[ny][nx]) continue;
            if (picture[ny][nx] != color) continue;
            visit[ny][nx] = 1;
            q.push(make_pair(ny, nx));
            ++size;
        }
    }
    return size;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    memset(visit, 0, sizeof(visit));
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int y = 0; y < m; ++y) {
        for (int x = 0; x < n; ++x) {
            if (visit[y][x] || picture[y][x] == 0) continue;
            max_size_of_one_area = max(max_size_of_one_area, bfs(y, x, m, n, picture));
            number_of_area++;
        }
    }
    return vector<int>{number_of_area, max_size_of_one_area};
}