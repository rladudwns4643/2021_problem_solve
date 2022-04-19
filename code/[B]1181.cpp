#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	vector<string> table;
	table.reserve(cnt);
	for (int i = 0; i < cnt; ++i) {
		string t;
		cin >> t;
		table.emplace_back(t);
	}

	sort(table.begin(), table.end(), [](const string& l, const string& r) {
		return l < r;
		});
	stable_sort(table.begin(), table.end(), [](const string& l, const string& r) {
		return l.size() < r.size();
		});
	table.erase(unique(table.begin(), table.end()), table.end());

	for (const auto& a : table) {
		cout << a << "\n";
	}
}