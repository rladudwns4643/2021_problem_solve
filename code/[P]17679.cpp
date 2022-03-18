#include <string>
#include <vector>
#include <cstring>
using namespace std;

constexpr pair<int, int> dir[4] = { {0,0}, {1,0}, {0,1}, {1,1} };
bool table[31][31];

int erase(int m, int n, vector<string>& board) {
	int cnt{ 0 };
	memset(table, false, sizeof(table));

	for (int i = 0; i < m - 1; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			if (board[i][j] == ' ') continue;
			if (board[i + dir[0].first][j + dir[0].second] == board[i + dir[1].first][j + dir[1].second]
				&& board[i + dir[0].first][j + dir[0].second] == board[i + dir[2].first][j + dir[2].second]
				&& board[i + dir[0].first][j + dir[0].second] == board[i + dir[3].first][j + dir[3].second]) {
				for (int k = 0; k < 4; ++k) {
					table[i + dir[k].first][j + dir[k].second] = true;
				}
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (table[i][j]) {
				board[i][j] = ' ';
				cnt++;
			}
		}
	}
	return cnt;
}

void drop(int m, int n, vector<string>& board) {
	for (int i = m - 2; i >= 0; --i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == ' ')continue;
			int cx = i;
			while (cx + 1 < m && board[cx + 1][j] == ' ') {
				board[cx + 1][j] = board[cx][j];
				board[cx][j] = ' ';
				cx++;
			}
		}
	}
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	int t{ 0 };
	do {
		t = erase(m, n, board);
		answer += t;
		drop(m, n, board);
	} while (t != 0);
	return answer;
}