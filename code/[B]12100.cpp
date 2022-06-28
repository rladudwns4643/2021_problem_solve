#include <iostream>
using namespace std;

constexpr int LIMIT{ 21 };
int t1[LIMIT][LIMIT];
int t2[LIMIT][LIMIT];
int n;

void rotate() {
	int tmp[LIMIT][LIMIT];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			tmp[i][j] = t2[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			t2[i][j] = tmp[n - 1 - j][i];
		}
	}
}

//0, 90, 180, 270
void tilt(int dir) {
	while (dir--) rotate();
	for (int i = 0; i < n; ++i) {
		int tilted[LIMIT];
		fill(&tilted[0], &tilted[LIMIT], 0);
		int idx{ 0 };
		for (int j = 0; j < LIMIT; ++j) {
			if (t2[i][j] == 0) continue;
			if (tilted[idx] == 0) tilted[idx] = t2[i][j];
			else if (tilted[idx] == t2[i][j]) {
				tilted[idx] *= 2;
				++idx;
			}
			else {
				++idx;
				tilted[idx] = t2[i][j];
			}
		}
		for (int j = 0; j < n; ++j) t2[i][j] = tilted[j];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> t1[i][j];
		}
	}
	int ans{ 0 };
	for (int tmp = 0; tmp < 1024; ++tmp) { //4^5
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				t2[i][j] = t1[i][j];
			}
		}
		int brute = tmp;
		for (int i = 0; i < 5; ++i) {
			int dir = brute % 4;
			brute /= 4;
			tilt(dir);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ans = max(ans, t2[i][j]);
			}
		}
	}
	cout << ans;
}