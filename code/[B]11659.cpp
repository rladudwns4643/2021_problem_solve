#include <iostream>
using namespace std;

int n, m, table[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> table[i];
		table[i] += table[i - 1];
	}

	for (int i = 0; i < m; ++i) {
		int s, e;
		cin >> s >> e;
		cout << table[e] - table[s - 1] << "\n";
	}
}