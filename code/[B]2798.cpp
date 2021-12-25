#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int ans{ 0 };
	vector<int> vi(n);
	for (auto& a : vi) cin >> a;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (i != j && i != k && j != k) {
					int t = vi[i] + vi[j] + vi[k];
					if (t <= m && ans < t) ans = t;
				}
			}
		}
	}
	cout << ans;
}