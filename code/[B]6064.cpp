#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		bool flag{ false };
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		--x;
		--y;
		for (int i = x; i < (m * n); i += m) {
			if (i % n == y) {
				flag = true;
				cout << i + 1 << "\n";
				break;
			}
		}
		if (!flag) cout << "-1\n";
	}
}