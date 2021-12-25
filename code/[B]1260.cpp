#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1000 + 1;

//정점의 개수, 간선의 개수, 시작점
int n, m, v;
int road[MAX][MAX];
bool visited[MAX];
queue<int> qi;

void DFS(int idx) {
	cout << idx << " ";
	for (int i = 0; i <= n; ++i) {
		if (road[idx][i] && !visited[i]) {
			visited[i] = true;
			DFS(i);
		}
	}
}

void BFS(int idx) {
	qi.push(idx);
	visited[idx] = 1;

	while (!qi.empty()) {
		idx = qi.front();
		qi.pop();
		cout << idx << " ";

		for (int i = 0; i <= n; ++i) {
			if (road[idx][i] && !visited[i]) {
				visited[i] = 1;
				qi.push(i);
			}
		}
	}
}

int main() {
	memset(visited, 0, sizeof(visited));
	memset(road, 0, sizeof(road));

	cin >> n >> m >> v;
	int from, to;
	for (int i = 0; i < m; ++i) {
		cin >> from >> to;
		road[from][to] = 1;
		road[to][from] = 1;
	}

	visited[v] = 1;
	DFS(v);
	cout << endl;

	memset(visited, 0, sizeof(visited));
	BFS(v);
	cout << endl;
}