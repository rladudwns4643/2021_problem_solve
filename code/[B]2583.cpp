#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k;
int table[101][101];
int ans = 0;
pair<int, int> dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int bfs(int r, int c) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ r, c });
	table[r][c] = 1;
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; ++i) {
			int nr = cr + dir[i].first;
			int nc = cc + dir[i].second;
			if (nr >= 0 && nr < n && nc >= 0 && nc < m
				&& table[nr][nc] == 0) {
				q.push({ nr, nc });
				table[nr][nc] = 1;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	priority_queue<int, vector<int>, greater<>> answer;
	for (int i = 0; i < k; ++i) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int c = x1; c < x2; ++c) {
			for (int r = y1; r < y2; ++r) {
				table[r][c] = 1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (table[i][j] == 0) {
				ans++;
				answer.push(bfs(i, j));
			}
		}
	}
	cout << ans << "\n";
	while (!answer.empty()) {
		cout << answer.top() << " ";
		answer.pop();
	}
	return 0;
}