#include <iostream>
#include <set>

using namespace std;

void solution() {
	int k;
	cin >> k;
	multiset<int> ms;
	for (int i = 0; i < k; ++i) {
		char c; int j;
		cin >> c >> j;
		if (c == 'I') ms.insert(j);
		if (c == 'D') {
			if (ms.empty()) continue;
			if (j == -1) ms.erase(ms.begin());
			if (j == 1) ms.erase(prev(ms.end()));
		}
	}
	if (ms.empty()) cout << "EMPTY\n";
	else cout << *prev(ms.end()) << *ms.begin() << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solution();
	}
}