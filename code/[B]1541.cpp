#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	bool flag = false;
	int ans{ 0 };

	cin >> input;

	for (int i = 0; i < input.size(); ++i) {
		string s;
		while (i < input.size() && input[i] != '+' && input[i] != '-') {
			s += input[i];
			++i;
		}
		flag ? ans -= stoi(s) : ans += stoi(s);
		if (!flag && input[i] == '-') flag = true;
	}

	cout << ans;
}