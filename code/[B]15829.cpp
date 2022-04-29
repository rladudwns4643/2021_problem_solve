#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ull;
constexpr int h = 1234567891;
ull make_hash(string s) {
	ull ret = 0;
	ull pow_n = 1;
	for (int i = 0; i < s.size(); ++i) {
		int c = s[i] - 'a' + 1;
		ret = (ret + (c * pow_n) % h) % h;
		pow_n = (pow_n * 31) % h;
	}
	return ret;
}
int main() {
	int len;
	string s;
	cin >> len >> s;
	cout << make_hash(s);
}