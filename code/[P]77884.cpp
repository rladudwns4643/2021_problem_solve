#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    vector<int> t;
    for (int i = 1; i < 32; ++i) {
        t.push_back(i * i);
    }
    for (int i = left; i <= right; ++i) {
        if (find(t.begin(), t.end(), i) != t.end()) answer -= i;
        else answer += i;
    }
    return answer;
}