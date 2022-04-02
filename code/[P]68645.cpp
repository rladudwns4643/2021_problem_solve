#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> numbers(n, vector<int>(n, 0));
    int num = 1, x = -1, y = 0, cur = n;

    for (int i = 0; i < n; i++) {
        for (int j = cur; j >= 1; j--) {
            if (i % 3 == 0) {
                ++x;
            }
            else if (i % 3 == 1) {
                ++y;
            }
            else if (i % 3 == 2) {
                --x;
                --y;
            }
            numbers[x][y] = num;
            ++num;
        }
        cur--;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            answer.push_back(numbers[i][j]);
    }

    return answer;
}