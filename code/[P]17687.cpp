#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string table = "0123456789ABCDEF";

string change(int num, int n) {
	string ret;
	if (num == 0) return "0";
	while (num > 0) {
		ret += table[num % n];
		num /= n;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string solution(int n, int t, int m, int p) {
	string answer = "";
	string temp = "";
	int nowNum = 0;
	for (int i = 0; temp.size() <= m * t; ++i) {
		temp += change(i, n);
	}
	for (int i = 0; i < t; ++i) {
		answer += temp[p - 1 + (i * m)];
	}
	return answer;
}