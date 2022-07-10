#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int row, col, ans, T;
char table[101][101];
bool visit[101][101];
pii dir[4] = { {1,0}, {-1, 0}, {0, 1}, {0, -1} };

bool bfs() {
	visit[0][0] = true;
	int cnt = 0;
	queue<pii> q;
	q.push({ 0,0 });
	T++;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = r + dir[i].first;
			int nc = c + dir[i].second;
			if (nr >= 0 && nr < row
				&& nc >= 0 && nc < col
				&& !visit[nr][nc]) {
				if (table[nr][nc] == '0') q.push({ nr, nc });
				else {
					table[nr][nc] = '0';
					cnt++;
				}
				visit[nr][nc] = true;
			}
		}
	}
	if (cnt == 0) {
		cout << --T << "\n" << ans;
		return true;
	}
	else {
		ans = cnt;
		return false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> row >> col;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> table[i][j];
		}
	}

	while (1) {
		if (bfs()) break;
		fill(&visit[0][0], &visit[100][101], false);
	}

	return 0;
}