#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	int n;
	string tag, name;

	while (t--) {
		map<string, int> m;
		cin >> n;
		while (n--) {
			cin >> name >> tag;
			m[tag]++;
		}
		int ans = 1;
		for (auto i : m) {
			ans *= (i.second + 1);
		}
		ans -= 1;
		cout << ans << "\n";
	}
	return 0;
}