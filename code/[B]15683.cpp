#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
int n, m, nm = 0;

pii dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int t1[10][10];
int t2[10][10];
vector<pii> cctv;

bool OutOfBounds(int a, int b) {
	return a < 0 || a >= n || b < 0 || b >= m;
}

void upd(int x, int y, int d) {
	d %= 4;
	while (1) {
		x += dir[d].first;
		y += dir[d].second;
		if (OutOfBounds(x, y)) return;
		if (t2[x][y] == 6) return;
		if (t2[x][y] != 0) continue;
		t2[x][y] = 7;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	fill(&t1[0][0], &t1[9][10], 0);
	fill(&t2[0][0], &t2[9][10], 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> t1[i][j];
			if (t1[i][j] != 0 && t1[i][j] != 6) cctv.emplace_back(make_pair(i, j));
			if (t1[i][j] == 0) nm++;
		}
	}

	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); ++tmp) { //4^cctv.size()
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				t2[i][j] = t1[i][j];
			}
		}
		int brute = tmp;
		for (int i = 0; i < cctv.size(); ++i) {
			int dir = brute % 4;
			brute /= 4;
			int x = cctv[i].first;
			int y = cctv[i].second;
			switch (t1[x][y]) {
			case 1: {
				upd(x, y, dir);
				break;
			}
			case 2: {
				upd(x, y, dir);
				upd(x, y, dir + 2);
				break;
			}
			case 3: {
				upd(x, y, dir);
				upd(x, y, dir + 1);
				break;
			}
			case 4: {
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
				break;
			}
			case 5: {
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
				upd(x, y, dir + 3);
				break;
			}
			}
		}
		int v = 0; //count 0
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				v += (t2[i][j] == 0);
			}
		}
		nm = min(nm, v);
	}
	cout << nm;
}