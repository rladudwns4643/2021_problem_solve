#include <iostream>
#include <algorithm>
using namespace std;
int N;
int map[101][101];
bool visit[101];

void dfs(int node) {
	for (int i = 0; i < N; ++i) {
		if (map[node][i] == 1 && !visit[i]) {
			visit[i] = true;
			dfs(i);
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		fill(&visit[0], &visit[101], false);
		dfs(i);
		for (int j = 0; j < N; ++j) {
			if (visit[j]) map[i][j] = 1;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}