#include <iostream>
#include <string>
using namespace std;
string input[65];

void solution(int s, int y, int x) {
	char cur = input[y][x];

	for (int i = y; i < y + s; ++i) {
		for (int j = x; j < x + s; ++j) {
			if (input[i][j] != cur) {
				cout << "(";
				solution(s / 2, y, x);
				solution(s / 2, y, x + s/2);
				solution(s / 2, y+s/2, x);
				solution(s / 2, y+s/2, x+s/2);
				cout << ")";
				return;
			}
		}
	}
	cout << cur;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> input[i];

	solution(N, 0, 0);
}