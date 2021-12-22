#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer{ 0 };
    vector<int> get(n, 1);

    for (auto& l : lost) get[l - 1]--;
    for (auto& r : reserve) get[r - 1]++;

    for (int i = 0; i < get.size(); ++i) {
        if (get[i] != 0) continue;
        if (i > 0 && get[i - 1] == 2) {
            get[i - 1]--;
            get[i]++;
            continue;
        }
        if (i != get.size() - 1 && get[i + 1] == 2) {
            get[i + 1]--;
            get[i]++;
            continue;
        }
    }
    for (auto a : get) {
        if (a != 0) answer++;
    }

    return answer;
}