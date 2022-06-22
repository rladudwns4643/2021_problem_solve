#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef pair<int, int> pii;

pii dir[4] = { {1,0}, {-1,0}, {0, 1}, {0, -1} };
string table[1001];
int fire[1001][1001];
int human[1001][1001];
int visit[1001][1001];
int c, r;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> r;
	fill(&fire[0][0], &fire[1000][1001], -1);
	fill(&human[0][0], &human[1000][1001], -1);
	for (int i = 0; i < c; ++i) {
		cin >> table[i];
	}

	queue<pii> q1;
	queue<pii> q2;
	for (int i = 0; i < c; ++i) {
		for (int j = 0; j < r; ++j) {
			if (table[i][j] == 'F') {
				q1.push({ i, j });
				fire[i][j] = 0;
			}
			if (table[i][j] == 'J') {
				q2.push({ i,j });
				human[i][j] = 0;
			}
		}
	}

	//불 bfs
	while (!q1.empty()) {
		auto cur = q1.front(); q1.pop();
		for (int d = 0; d < 4; ++d) {
			int nx = cur.first + dir[d].first;
			int ny = cur.second + dir[d].second;
			if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
			if (fire[nx][ny] >= 0 || table[nx][ny] == '#') continue;
			fire[nx][ny] = fire[cur.first][cur.second] + 1;
			q1.push({ nx, ny });
		}
	}

	//사람 bfs
	while (!q2.empty()) {
		auto cur = q2.front(); q2.pop();
		for (int d = 0; d < 4; ++d) {
			int nx = cur.first + dir[d].first;
			int ny = cur.second + dir[d].second;
			if (nx < 0 || nx >= c || ny < 0 || ny >= r) {
				cout << human[cur.first][cur.second] + 1;
				return 0;
			}
			if (human[nx][ny] >= 0 || table[nx][ny] == '#') continue;
			if (fire[nx][ny] != -1 && fire[nx][ny] <= human[cur.first][cur.second] + 1) continue; //불보다 늦어도 못감
			human[nx][ny] = human[cur.first][cur.second] + 1;
			q2.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE";
}