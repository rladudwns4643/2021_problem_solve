#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n;
	int sum = 0;
	cin >> n;
	vector<int> table(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> table[i];
		sum += table[i];
	}

	stable_sort(table.begin(), table.end(), [](const int& l, const int& r) {
		return l < r;
		});
	int a, b, c, d;
	float avg = sum / (float)n;
	a = round(avg);
	b = table[n / 2];

	int curNum = 8000;
	int curCnt = 1;
	int result = 0;
	int maxCnt = 0;
	int sameCnt = 0;
	for (int i = 0; i < n; ++i) {
		if (table[i] != curNum) {
			curNum = table[i];
			curCnt = 1;
		}
		else if (table[i] == curNum) {
			curCnt++;
		}
		if (curCnt > maxCnt) {
			maxCnt = curCnt;
			result = table[i];
			sameCnt = 0;
		}
		else if (curCnt == maxCnt && sameCnt < 1) {
			sameCnt++;
			result = table[i];
		}
	}
	c = result;

	d = table.back() - table.front();

	cout << a << "\n" << b << "\n" << c << "\n" << d;
}