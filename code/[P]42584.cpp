#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer;
    for (int i = 0; i < n - 2; i++) {
        int time = 1;
        for (int j = i + 1; j < n - 1; j++) {
            if (prices[i] > prices[j]) break;
            time++;
        }
        answer.push_back(time);
    }
    answer.push_back(1);
    answer.push_back(0);
    return answer;
}