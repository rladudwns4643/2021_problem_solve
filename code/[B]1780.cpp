#include <iostream>
#include <vector>
using namespace std;

int table[2188][2188];
int ans[3];

void solution(int cx, int cy, int s) {
	bool flag = true;
	for (int i = cx; i < cx + s; ++i) {
		for (int j = cy; j < cy + s; ++j) {
			if (table[cx][cy] != table[i][j]) {
				flag = false;
				break;
			}
		}
	}
	if (flag) ans[(table[cx][cy]) + 1]++;
	else {
		int ns = s / 3;
		for (int a = cx; a < cx + s; a += ns) {
			for (int b = cy; b < cy + s; b += ns) {
				solution(a, b, ns);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int c;
	cin >> c;

	for (int i = 0; i < c; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> table[i][j];
		}
	}

	solution(0, 0, c);

	cout << ans[0] << "\n" << ans[1] << "\n" << ans[2] << "\n";
}