#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<bool> ban(10, false);

bool check(int target) {
	string s = to_string(target);
	int size = s.size();
	for (int i = 0; i < size; ++i) {
		if (ban[s[i] - 48]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int target, cnt, t;
	cin >> target >> cnt;
	for (int i = 0; i < cnt; ++i) {
		cin >> t;
		ban[t] = true;
	}

	string s = to_string(target);
	int ans = abs(target - 100);
	for (int i = 0; i <= 1000000; ++i) {
		if (check(i)) {
			int tmp = abs(target - i) + to_string(i).length();
			ans = min(ans, tmp);
		}
	}
	cout << ans;
}