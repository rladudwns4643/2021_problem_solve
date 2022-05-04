#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int cur = 0;
	int n;
	cin >> n;
	vector<int> table(n, 0);
	vector<char> ans;
	vector<int> v;
	ans.reserve(n);
	v.reserve(n);
	for (int i = 0; i < n; ++i) cin >> table[i];
	for (int i = 1; i <= n; ++i) {
		v.emplace_back(i);
		ans.emplace_back('+');

		while (!v.empty() && v.back() == table[cur]) {
			v.pop_back();
			ans.emplace_back('-');
			cur++;
		}
	}
	if (!v.empty()) cout << "NO";
	else {
		for (const auto& a : ans) {
			cout << a << "\n";
		}
	}
}