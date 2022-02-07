#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int cur{ 0 };
    priority_queue<int, vector<int>, greater<int>> q(scoville.begin(), scoville.end());

    while (q.size() > 1 && q.top() < K) {
        int first = q.top();
        q.pop();

        int sec = q.top();
        q.pop();

        q.push(first + (sec * 2));
        ++answer;
    }
    if (q.top() < K) return -1;

    return answer;
}