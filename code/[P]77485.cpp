#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int g_arr[100][100];
int g_min;

vector<int> solution(int row, int col, vector<vector<int>> queries) {
	vector<int> answer;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			g_arr[i][j] = i * col + j + 1;
		}
	}

	for (int i = 0; i < queries.size(); ++i) {
		g_min = row * col;

		int y1 = queries[i][0] - 1;
		int x1 = queries[i][1] - 1;
		int y2 = queries[i][2] - 1;
		int x2 = queries[i][3] - 1;
		int t = g_arr[y1][x1];
		g_min = min(g_min, t);

		for (int j = y1; j < y2; ++j) {
			g_arr[j][x1] = g_arr[j + 1][x1];
			g_min = min(g_min, g_arr[j + 1][x1]);
		}
		for (int j = x1; j < x2; ++j) {
			g_arr[y2][j] = g_arr[y2][j + 1];
			g_min = min(g_min, g_arr[y2][j + 1]);
		}
		for (int j = y2; j > y1; --j) {
			g_arr[j][x2] = g_arr[j - 1][x2];
			g_min = min(g_min, g_arr[j - 1][x2]);
		}
		for (int j = x2; j > x1 + 1; --j) {
			g_arr[y1][j] = g_arr[y1][j - 1];
			g_min = min(g_min, g_arr[y1][j - 1]);
		}
		g_arr[y1][x1 + 1] = t;
		answer.push_back(g_min);
	}
	return answer;
}