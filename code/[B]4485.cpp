#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

pii dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n;
int arr[131][131];
int dist[131][131];

void bfs() {
	queue<pii> q;
	q.push({ 0,0 });
	dist[0][0] = arr[0][0];
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dir[i].first;
			int nx = x + dir[i].second;
			if (ny >= 0 && ny < n && nx >= 0 && nx < n
				&& dist[ny][nx] > dist[y][x] + arr[ny][nx]) {
				dist[ny][nx] = dist[y][x] + arr[ny][nx];
				q.push({ ny,nx });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c = 1;
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> arr[i][j];
				dist[i][j] = 987654321;
			}
		}
		bfs();
		cout << "Problem " << c++ << ": " << dist[n - 1][n - 1] << "\n";
	}
	return 0;
}