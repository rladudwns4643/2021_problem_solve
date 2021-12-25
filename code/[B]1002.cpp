#include <iostream>
using namespace std;


int x1, y1, r1, x2, y2, r2;

int sq(int x) {
	return x * x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

		if (r1 == r2 && x1 == x2 && y1 == y2)cout << -1;
		else if (d > sq(r1 + r2))cout << 0;
		else if (d == sq(r1 + r2))cout << 1;
		else if (d < sq(r1 + r2)) {
			if (d > sq(r2 - r1))cout << 2;
			else if (d == sq(r2 - r1))cout << 1;
			else if (d < sq(r2 - r1))cout << 0;
		}
		cout << '\n';
	}
}