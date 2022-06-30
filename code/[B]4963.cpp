#include <iostream>
#include <queue>
using namespace std;

int w, h, ans;
int graph[51][51];
bool visit[51][51];
typedef pair<int, int> pii;
pii dir[8] = {
	{1, 0}, {0, 1}, {-1, 0}, {0, -1}, 
	{1, 1}, {-1, -1}, {1, -1}, {-1, 1}
};

void bfs(int h, int w) {
	queue<pii> q;
	q.push({ h,w });
	visit[h][w] = true;
	while (!q.empty()) {
		h = q.front().first;
		w = q.front().second;
		q.pop();

		for (int i = 0; i < 8; ++i) {
			int nh = h + dir[i].first;
			int nw = w + dir[i].second;

			if (0 <= nh && 0 <= nw && nh < 50 && nw < 50) {
				if (graph[nh][nw] && !visit[nh][nw]) {
					visit[nh][nw] = true;
					q.push({ nh, nw });
				}
			}
		}
	}
}

void dfs(int h, int w) {
	visit[h][w] = true;
	for (int i = 0; i < 8; ++i) {
		int nh = h + dir[i].first;
		int nw = w + dir[i].second;

		if (0 <= nh && 0 <= nw && nh < 50 && nw < 50) {
			if (graph[nh][nw] && !visit[nh][nw]) {
				visit[nh][nw] = true;
				dfs(nh, nw);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> graph[i][j];
			}
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (graph[i][j] == 1 && visit[i][j] == 0) {
					ans++;
					bfs(i, j);
				}
			}
		}
		cout << ans;

		fill(&graph[0][0], &graph[50][51], 0);
		fill(&visit[0][0], &visit[50][51], false);
		ans = 0;
	}
}