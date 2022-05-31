#include <iostream>

using namespace std;

char table[101][101];
bool visit[101][101];
int N{ 0 };
typedef pair<int, int> pii;

pii dir[4] = { {0,-1}, {0,1}, {-1,0}, {1,0} };

void dfs(int cx, int cy) {
	visit[cx][cy] = true;
	for (int i = 0; i < 4; ++i) {
		int nx = cx + dir[i].first;
		int ny = cy + dir[i].second;

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (!visit[nx][ny] && table[cx][cy] == table[nx][ny]) dfs(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int ans{ 0 };
	for (int i = 0; i < N; ++i) cin >> table[i];

	fill(&visit[0][0], &visit[100][101], false);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visit[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << " ";
	ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (table[i][j] == 'G') table[i][j] = 'R';
			else table[i][j] = table[i][j];
		}
	}
	fill(&visit[0][0], &visit[100][101], false);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visit[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}

	cout << ans;
}