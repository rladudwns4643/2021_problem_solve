#include <iostream>
using namespace std;

int table[9] = { 0, };
bool visit[9] = { false, };
int n, m;
void dfs(int num, int c, int n, int m) {
	if (c == m) {
		for (int i = 0; i < m; ++i) cout << table[i] << ' ';
		cout << "\n";
		return;
	}
	for (int i = num; i <= n; ++i) {
		if (!visit[i]) {
			visit[i] = true;
			table[c] = i;
			dfs(i + 1, c + 1, n, m);
			visit[i] = false;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	dfs(1, 0, n, m);
	return 0;
}