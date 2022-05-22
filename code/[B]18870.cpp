#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt;
	cin >> cnt;
	vector<int> table;
	table.reserve(cnt);
	map<int, int> answer;
	for (int i = 0; i < cnt; ++i) {
		cin >> table[i];
		answer.insert({ table[i], 0 });
	}
	int cur = 0;
	for (auto it = answer.begin(); it != answer.end(); ++it) {
		it->second = cur;
		++cur;
	}
	for (int i = 0; i < cnt; ++i) cout << answer[table[i]] << " ";
}