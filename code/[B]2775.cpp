#include <iostream>
#include <vector>
using namespace std;

int apt[101][15];
void make_table() {
	for (int i = 0; i < 100; ++i) {
		for (int j = 1; j < 15; ++j) {
			if (i == 0) apt[0][j] = j;
			else if (j == 1) apt[i][1] = 1;
			else apt[i][j] = apt[i][j - 1] + apt[i - 1][j];
		}
	}
}

int main() {
	make_table();
	int cnt;
	cin >> cnt;
	vector<int> answer;
	answer.reserve(cnt);

	for (int i = 0; i < cnt; ++i) {
		int k, n;
		cin >> k >> n;
		answer.emplace_back(apt[k][n]);
	}

	for (const auto& a : answer) cout << a << endl;
}