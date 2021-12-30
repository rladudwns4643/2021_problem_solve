#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int base{ 0 };
    int zero{ 0 };

    for (auto& a : lottos) {
        if (a == 0) {
            ++zero;
            continue;
        }
        if (find(win_nums.begin(), win_nums.end(), a) != win_nums.end()) {
            ++base;
        }
    }
    if (zero == 0 && base == 0) {
        answer.emplace_back(6);
        answer.emplace_back(6);
        return answer;
    }
    answer.emplace_back(7 - (base + zero));
    if (7 - base >= 7) answer.emplace_back(6);
    else answer.emplace_back(7 - base);
    return answer;
}