#include <iostream>
using namespace std;

typedef pair<int, int> pii;
pii dir[4] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
int table[501][501];
bool visit[501][501];
int N, M;
int answer;

void findSpacial(int cy, int cx) {
	// ぬ
	if (cy + 1 < N && cx + 2 < M) answer = max(answer, table[cy][cx] + table[cy][cx + 1] + table[cy][cx + 2] + table[cy + 1][cx + 1]);
	// た
	if (cy + 2 < N && cx + 1 < M) answer = max(answer, table[cy][cx] + table[cy + 1][cx] + table[cy + 1][cx + 1] + table[cy + 2][cx]);
	// で
	if (cy - 1 >= 0 && cx + 2 < M) answer = max(answer, table[cy][cx] + table[cy][cx + 1] + table[cy][cx + 2] + table[cy - 1][cx + 1]);
	// っ
	if (cy + 2 < N && cx - 1 >= 0) answer = max(answer, table[cy][cx] + table[cy + 1][cx] + table[cy + 1][cx - 1] + table[cy + 2][cx]);
}

void findNormal(int d, int s, int cy, int cx) {
	if (d == 3) {
		answer = max(answer, s);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int ny = cy + dir[i].first, nx = cx + dir[i].second;
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (visit[ny][nx]) continue;
		visit[ny][nx] = true;
		findNormal(d + 1, s + table[ny][nx], ny, nx);
		visit[ny][nx] = false;
	}
}


void getMax(int y, int x) {
	findSpacial(y, x);
	visit[y][x] = true;
	findNormal(0, table[y][x], y, x);
	visit[y][x] = false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	answer = 0;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> table[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			getMax(i, j);
		}
	}

	cout << answer;
}