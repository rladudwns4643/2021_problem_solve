#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int caseCnt = 0;
	cin >> caseCnt;
	vector<int> ans(caseCnt, 0);
	for (int i = 0; i < caseCnt; ++i) {
		int n, k;
		cin >> n >> k;
		queue<pair<int, bool>> table;
		vector<int> val(n, 0);
		for (int j = 0; j < n; ++j) {
			int t;
			cin >> t;
			table.push({ t, j == k });
			val[j] = t;
		}
		stable_sort(val.begin(), val.end(), [](const int& l, const int& r) {
			return l < r;
			});
		for (int k = 1; ;) {
			pair<int,int> t = table.front();
			if (t.first == val.back()) {
				table.pop();
				val.pop_back();
				if (t.second == true) {
					ans[i] = k;
					break;
				}
				++k;
			}
			else {
				table.pop();
				table.push(t);
			}
		}
	}
	for (const auto& a : ans) {
		cout << a << "\n";
	}
}