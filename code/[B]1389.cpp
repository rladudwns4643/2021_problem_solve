#include <iostream>
#include <vector>

using namespace std;
int table[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int node1, node2;
		cin >> node1 >> node2;
		table[node1][node2] = table[node2][node1] = 1;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j) continue;
				else if (table[i][k] && table[k][j]) {
					if (table[i][j] == 0) table[i][j] = table[i][k] + table[k][j];
					else table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
				}
			}
		}
	}

	int result{ 987654321 };
	int ans{ 0 };
	for (int i = 1; i <= n; ++i) {
		int sum{ 0 };
		for (int j = 1; j <= n; ++j) sum += table[i][j];
		if (result > sum) {
			result = sum;
			ans = i;
		}
	}

	cout << ans;
}