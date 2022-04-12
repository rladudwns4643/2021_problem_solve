#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    for (int i = 11; i >= 0; i--)
        if (a[i] != b[i]) return a[i] > b[i];
    return false;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ret(12, -1);
    vector<int> brute(n + 10);
    fill(brute.begin() + n, brute.end(), 1);
    do {
        vector<int> arrow;
        int before = -1;
        for (int i = 0; i < n + 10; i++) {
            if (brute[i]) {
                arrow.emplace_back(i - before - 1);
                before = i;
            }
        }
        arrow.emplace_back(n + 10 - before - 1);
        int score = 0;
        for (int i = 0; i <= 10; i++) {
            if (arrow[i] > info[i])
                score += (10 - i);
            else if (info[i] != 0)
                score -= (10 - i);
        }
        if (score <= 0) continue;
        arrow.emplace_back(score);
        if (cmp(arrow, ret)) ret = arrow;
    } while (next_permutation(brute.begin(), brute.end()));
    if (ret[0] == -1) return vector<int>({ -1 });
    ret.pop_back();
    return ret;
}