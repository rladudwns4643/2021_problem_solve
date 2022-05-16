#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<string, int> table;
	set<string> ans;
	for (int i = 0; i < n + m; ++i) {
		string t;
		cin >> t;
		table[t]++;
		if (table[t] > 1) ans.insert(t);
	}

	cout << ans.size() << '\n';
	for (const auto& a : ans) {
		cout << a << '\n';
	}
}