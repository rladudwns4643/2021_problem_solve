#include <iostream>
#include <queue>
using namespace std;
int epic_move[101];
int visit[101];
void bfs() {
	queue<int> q;
	fill(&visit[0], &visit[101], -1);
	q.push(1);
	visit[1] = 0;
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		for (int i = 1; i <= 6; ++i) {
			int nc = c + i;
			if (nc > 100) continue;
			if (epic_move[nc] != 0) nc = epic_move[nc];
			if (visit[nc] == -1) {
				visit[nc] = visit[c] + 1;
				q.push(nc);
			}
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	int t = n + m;
	while (t--) {
		int i1, i2; cin >> i1 >> i2;
		epic_move[i1] = i2;
	}

	bfs();
	::cout << visit[100];
	return 0;
}