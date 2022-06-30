#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define X first
#define Y second
int ans = -1;
bool c[8][8];
pair<int, int> dir[4] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
int n, m;

void check(vector<vector<int>> a, vector<pair<int, int>>& virus) {
    queue<pair<int, int>> q;
    for (auto x : virus) {
        q.push(x);
        c[x.X][x.Y] = true;
    }
    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i].X;
            int ny = y + dir[i].Y;
            if (0 <= nx && nx < n && 0 <= ny && ny < m) { //oob
                if (c[nx][ny] == false && a[nx][ny] == 0) {
                    c[nx][ny] = true;
                    a[nx][ny] = 2;
                    q.push({ nx,ny });
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0)
                cnt += 1;
        }
    }

    if (ans < cnt) {
        ans = cnt;
    }
}

void wall(vector<vector<int>> a, int cnt, int z, vector<pair<int, int>>& virus) {
    if (cnt == 3) { //벽이 3개 만들어지면 체크
        memset(c, false, sizeof(c));
        check(a, virus);
        return;
    }

    //row major order
    for (int i = z; i < n * m; i++) {
        if (a[i / m][i % m] != 0) continue;
        a[i / m][i % m] = 1;
        wall(a, cnt + 1, z + 1, virus);
        a[i / m][i % m] = 0;
    }
}

int main() {
    cin >> n >> m;
    vector<pair<int, int>> virus;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                virus.push_back({ i, j });
            }
        }
    }
    wall(a, 0, 0, virus);

    cout << ans << '\n';
    return 0;
}