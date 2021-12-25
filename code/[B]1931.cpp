#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int endT, ans;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pii> table(n);

	for (int i = 0; i < n; ++i) {
		int t1, t2;
		cin >> t1 >> t2;
		table[i].second = t1;
		table[i].first = t2;
	}

	sort(table.begin(), table.end());

	for (const auto& a : table) {
		if (a.second >= endT) {
			ans++;
			endT = a.first;
		}
	}
	cout << ans << "\n";
}