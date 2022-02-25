#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;

    for (int i = 0; i < priorities.size(); ++i) {
        pq.push(priorities[i]);
        q.push(make_pair(priorities[i], i));
    }

    while (1) {
        int prio = q.front().first;
        int idx = q.front().second;

        q.pop();

        if (prio == pq.top()) {
            pq.pop();
            ++answer;
            if (idx == location) break;
        }
        else {
            q.push(make_pair(prio, idx));
        }
    }
    return answer;
}