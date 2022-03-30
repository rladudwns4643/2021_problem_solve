#include <string>
#include <vector>

using namespace std;

int zero{ 0 };
int one{ 0 };

bool check(vector<vector<int>>& t, int i, int j, int size) {
    for (int x = i; x < i + size; ++x) {
        for (int y = j; y < j + size; ++y) {
            if (t[i][j] != t[x][y]) return false;
        }
    }
    return true;
}

void cut(vector<vector<int>>& t, int i, int j, int size) {
    int half = size / 2;
    if (!check(t, i, j, size)) {
        cut(t, i, j, half);
        cut(t, i, j + half, half);
        cut(t, i + half, j, half);
        cut(t, i + half, j + half, half);
    }
    else {
        if (t[i][j] == 1) ++one;
        else ++zero;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    cut(arr, 0, 0, arr.size());
    return { zero, one };
}