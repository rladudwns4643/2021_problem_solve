#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time{ 0 };
    int next_t{ 0 };
    int w{ 0 };
    queue<int> on_bridge;
    for (int i = 0; i < bridge_length; ++i) {
        on_bridge.push(0);
    }
    while (!on_bridge.empty()) {
        ++time;
        w -= on_bridge.front();
        on_bridge.pop();

        if (next_t < truck_weights.size()) {
            if (w + truck_weights[next_t] <= weight) {
                w += truck_weights[next_t];
                on_bridge.push(truck_weights[next_t]);
                ++next_t;
            }
            else { on_bridge.push(0); }
        }
    }
    return time;
}