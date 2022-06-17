#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	string s; cin >> s;
	int index = s.find('*');
	string p1 = s.substr(0, index);
	string p2 = s.substr(index + 1);
	while (t--) {
		string tmp = "";
		cin >> tmp;
		if (p1.size() + p2.size() > tmp.size()) cout << "NE\n";
		else if (tmp.find(p1) == 0) {
			string ex = tmp.substr(tmp.size() - (p2.size()));
			if (ex == p2) cout << "DA\n";
			else cout << "NE\n";
		}
		else cout << "NE\n";
	}
}