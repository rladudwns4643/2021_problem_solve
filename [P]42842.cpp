#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    vector<pair<int, int>> yack;
    for (int i = 1; i <= sqrt(yellow); ++i) {
        if (yellow % i == 0) yack.emplace_back(pair<int, int>(i, yellow / i));
    }
    for (int i = 0; i < yack.size(); ++i) {
        int& y = yack[i].first;
        int& x = yack[i].second;
        if (((x + 2) * (y + 2)) - (x * y) == brown) {
            answer.emplace_back(x + 2);
            answer.emplace_back(y + 2);
            break;
        }
    }
    return answer;
}