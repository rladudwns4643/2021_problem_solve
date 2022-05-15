#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string name[100001];
	map<string, int> table;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		name[i] = s;
		table.insert({ s,i });
	}

	for (int i = 1; i <= m; ++i) {
		string s;
		int n;
		cin >> s;
		if (isdigit(s[0]) == true) {
			n = stoi(s);
			cout << name[n] << '\n';
		}
		else {
			auto it = table.find(s);
			cout << it->second << '\n';
		}
	}

}