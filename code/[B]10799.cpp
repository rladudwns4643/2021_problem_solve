#include <iostream>
#include <string>
using namespace std;

int solution(const string& str) {
	int cnt{ 0 }, ans{ 0 }, len{ str.length() };
	for (int i = 0; i < len; ++i) {
		if (str[i] == '(') cnt++;
		else {
			cnt -= 1;
			if (str[i - 1] == '(') ans += cnt;
			else ans += 1;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	cout << solution(s);
}