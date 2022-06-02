#include <iostream>
#include <queue>
using namespace std;
int graph[101][101][101];
class xyh {
public:
	int x, y, h;
};
queue<xyh> q;
xyh dir[6] = {
	{1, 0, 0},
	{0, 1, 0},
	{-1, 0, 0},
	{0, -1, 0},
	{0, 0, 1},
	{0, 0, -1} };

int Y, X, H;

void bfs() {
	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		++cnt;
		for (int i = 0; i < size; ++i) {
			int cx = q.front().x;
			int cy = q.front().y;
			int ch = q.front().h;
			q.pop();
			for (int j = 0; j < 6; ++j) {
				if (cx + dir[j].x >= 0 && cx + dir[j].x < X
					&& cy + dir[j].y >= 0 && cy + dir[j].y < Y
					&& ch + dir[j].h >= 0 && ch + dir[j].h < H
					&& graph[cx + dir[j].x][cy + dir[j].y][ch + dir[j].h] == 0) {
					q.push({ cx + dir[j].x, cy + dir[j].y, ch + dir[j].h });
					graph[cx + dir[j].x][cy + dir[j].y][ch + dir[j].h] = 1;
				}
			}
		}
	}

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < Y; ++j) {
			for (int k = 0; k < X; ++k) {
				if (graph[k][j][i] == 0) {
					cout << "-1";
					return;
				}
			}
		}
	}
	cout << cnt - 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> X >> Y >> H;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < Y; ++j) {
			for (int k = 0; k < X; ++k) {
				cin >> graph[k][j][i];
				if (graph[k][j][i] == 1) {
					q.push({ k, j, i });
				}
			}
		}
	}
	bfs();

	return 0;
}