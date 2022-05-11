#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	while (1) {
		string t;
		getline(cin, t);
		if (t == ".") break;
		stack<char> s;
		bool ans = true;
		for (const auto& a : t) {
			if (a == '[' || a == '(') s.push(a);
			if (a == ']') {
				if (s.empty() || s.top() == '(') ans = false;
				else s.pop();
			}
			if (a == ')') {
				if (s.empty() || s.top() == '[') ans = false;
				else s.pop();
			}
		}
		if (s.empty() && ans) cout << "yes\n";
		else cout << "no\n";
	}
}