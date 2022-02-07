#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cur{ 0 };
    while (cur < progresses.size()) {
        for (int i = 0; i < progresses.size(); ++i) {
            progresses[i] += speeds[i];
        }

        int t{ 0 };
        for (int i = cur; i < progresses.size(); ++i) {
            if (progresses[i] < 100) break;
            t++;
        }
        if (t != 0) {
            cur += t;
            answer.push_back(t);
        }
    }
    return answer;
}