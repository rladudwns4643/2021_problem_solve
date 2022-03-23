#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int w = board[0].size();
    int h = board.size();
    if (w == 1 && h == 1) return 1;

    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (board[i][j] == 0) continue;
            board[i][j] = min(board[i - 1][j - 1], min(board[i][j - 1], board[i - 1][j])) + 1;
            answer = max(answer, board[i][j] * board[i][j]);
        }
    }
    return answer;
}