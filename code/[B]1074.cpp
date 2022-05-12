#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int ans;

void solution(int y, int x, int size) {
	if (y == r && x == c) {
		cout << ans;
		return;
	}

	if (r < y + size
		&& r >= y
		&& c < x + size
		&& c >= x) {
		int nsize = size / 2;
		solution(y, x, nsize);
		solution(y, x + nsize, nsize);
		solution(y + nsize, x, nsize);
		solution(y + nsize, x + nsize, nsize);
	}
	else {
		ans += size * size;
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> r >> c;
	solution(0, 0, pow(2, n));
}