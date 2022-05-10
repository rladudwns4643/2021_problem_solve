#include <iostream>
using namespace std;
int main() {
	int n, m, b;
	int map[501][501];
	int leastTime = 987654321;
	int height;
	cin >> n >> m >> b;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cin >> map[i][j];
	}
	for (int h = 0; h <= 256; ++h) {
		int build = 0;
		int remove = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int he = map[i][j] - h;
				if (he > 0) remove += he;
				else if (he < 0) build -= he;
			}
		}
		if (remove + b >= build) {
			int time = remove * 2 + build;
			if (leastTime >= time) {
				leastTime = time;
				height = h;
			}
		}
	}
	cout << leastTime << ' ' << height << '\n';
}