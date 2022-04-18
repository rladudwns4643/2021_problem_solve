#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool solution(int input) {
	string s{ to_string(input) };
	int cnt = s.size();
	for (int i = 0; i < cnt / 2; ++i) {
		if (s[i] != s[cnt - i - 1]) return false;
	}
	return true;
}

int main() {
	int t = -1;
	vector<int> table;
	while(1){
		cin >> t;
		if (t == 0) break;
		table.emplace_back(t);
	}

	for (const auto& a : table) {
		if (solution(a) == true) cout << "yes\n";
		else cout << "no\n";
	}
}