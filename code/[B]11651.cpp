#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	vector<pair<int, int>> table;
	table.reserve(t);
	while (t--) {
		int i1, i2;
		cin >> i1 >> i2;
		table.emplace_back(i1, i2);
	}
	stable_sort(table.begin(), table.end(), [](const pair<int, int>& l, const pair<int, int>& r) {
		if (l.second == r.second) {
			return l.first < r.first;
		}
		return l.second < r.second;
		});
	for (const auto& a : table) {
		cout << a.first << " " << a.second << "\n";
	}
}