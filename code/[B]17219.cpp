#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<string, string> mss;

	while (n--) {
		string s1, s2;
		cin >> s1 >> s2;
		mss[s1] = s2;
	}

	while (m--) {
		string s;
		cin >> s;
		cout << mss[s] << "\n";
	}
}