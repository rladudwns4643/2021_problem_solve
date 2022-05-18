#include <iostream>
using namespace std;

int n = 0;
int table[129][129];
int blue = 0, white = 0;
int check(int sx, int sy, int size) {
	int cur = table[sx][sy];
	for (int i = sx; i < sx + size; ++i) {
		for (int j = sy; j < sy + size; ++j) {
			if (table[i][j] != cur) return -1;
		}
	}
	return cur;
}

void solution(int sx, int sy, int size) {
	if (check(sx, sy, size) == 0) ++white;
	else if (check(sx, sy, size) == 1) ++blue;
	else {
		int next_size = size / 2;
		solution(sx, sy, next_size);
		solution(sx + next_size, sy, next_size);
		solution(sx, sy + next_size, next_size);
		solution(sx + next_size, sy + next_size, next_size);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> table[i][j];
		}
	}
	solution(0, 0, n);

	cout << white << '\n' << blue;
}