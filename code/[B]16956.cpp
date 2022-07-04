#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int R, C;
char arr[501][501];
pii dir[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
	queue<pii> dog;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 'W') dog.push({ i,j });
		}
	}

	while (!dog.empty()) {
		int y = dog.front().first;
		int x = dog.front().second;
		dog.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dir[i].first;
			int nx = x + dir[i].second;
			if(ny >= 0 && ny < R&& nx >= 0 && nx < C) {
				if (arr[ny][nx] == '.') arr[ny][nx] = 'D';
				else if (arr[ny][nx] == 'S') {
					cout << "0\n";
					return 0;
				}
			}
		}
	}
	cout << "1\n";
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}