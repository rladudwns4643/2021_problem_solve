#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

struct Shark {
	int y, x, dist;
	bool operator<(const Shark& s) const {
		if (dist == s.dist) {
			if (y == s.y) return x > s.x;
			return y > s.y;
		}
		return dist > s.dist;
	}
};

int N;
int table[21][21];
typedef pair<int, int> pii;
pii dir[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
queue<Shark> q;

int getMaxTime() {
	int t = 0, eat = 0, size = 2;
	//최단거리
	while (1) {
		priority_queue<Shark> feed;
		int visit[21][21];
		fill(&visit[0][0], &visit[20][21], false);
		while (!q.empty()) {
			Shark cur = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i) {
				int ny = cur.y + dir[i].first;
				int nx = cur.x + dir[i].second;
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (visit[ny][nx] || table[ny][nx] > size) continue;
				visit[ny][nx] = true;
				q.push({ ny,nx,cur.dist + 1 });
				if (table[ny][nx] < size && table[ny][nx] != 0) feed.push({ ny, nx, cur.dist + 1 });
			}
		}
		//먹기
		if (feed.empty()) break;
		Shark select = feed.top();
		int feedY = select.y;
		int feedX = select.x;
		int feedSize = table[feedY][feedX];
		eat++;
		if (eat == size) {
			eat = 0;
			size++;
		}
		table[feedY][feedX] = 0;
		q.push({ feedY, feedX, 0 });

		t += select.dist;
	}
	return t;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> table[i][j];
			if (table[i][j] == 9) {
				table[i][j] = 0;
				q.push({ i, j, 0 });
			}
		}
	}
	cout << getMaxTime() << "\n";
}