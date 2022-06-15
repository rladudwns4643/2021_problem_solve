#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef pair<int, string> pis;
int a, b;
bool visited[10001];

void bfs() {
	queue<pis> q;
	q.push({ a, "" });
	visited[a] = true;

	while (!q.empty()) {
		int c_num = q.front().first;
		string c_op = q.front().second;
		q.pop();

		if (c_num == b) {
			cout << c_op << "\n";
			return;
		}
		int D, S, L, R, t;
		D = (c_num * 2) % 10000;
		if (!visited[D]) {
			visited[D] = true;
			q.push({ D, c_op + "D" });
		}
		S = (c_num - 1) < 0 ? 9999 : c_num - 1;
		if (!visited[S]) {
			visited[S] = true;
			q.push({ S, c_op + "S" });
		}
		L = (c_num % 1000) * 10 + (c_num / 1000);
		if (!visited[L]) {
			visited[L] = true;
			q.push({ L, c_op + "L" });
		}
		R = (c_num / 10) + (c_num % 10) * 1000;
		if (!visited[R]) {
			visited[R] = true;
			q.push({ R, c_op + "R" });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		fill(&visited[0], &visited[10001], false);
		bfs();
	}
	return 0;
}