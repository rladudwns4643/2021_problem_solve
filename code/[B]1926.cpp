#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
int n, m;
int table[501][501];
bool visit[501][501];
int mx{ 0 };
int picture{ 0 };
pii dir[4] = { {1,0}, {-1, 0}, {0, 1}, {0, -1} };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> table[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (table[i][j] == 0 || visit[i][j]) continue;
			picture++;
			queue<pii> Q;
			visit[i][j] = 1;
			Q.push({ i,j });
			int area{ 0 };
			while (!Q.empty()) {
				area++;
				pii cur = Q.front(); Q.pop();
				for (int d = 0; d < 4; ++d) {
					int ny = cur.first + dir[d].first;
					int nx = cur.second + dir[d].second;
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if (visit[ny][nx] || table[ny][nx] != 1) continue;
					visit[ny][nx] = 1;
					Q.push({ ny, nx });
				}
			}
			mx = max(mx, area);
		}
	}
	cout << picture << "\n" << mx;
}