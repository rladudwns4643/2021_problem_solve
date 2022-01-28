#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int t = n * m;
    if (m > n) {
        int t = m;
        m = n;
        n = t;
    }

    while (1) {
        int t = m;
        m = n % m;
        n = t;
        if (m == 0) break;
    }
    answer.push_back(n);
    answer.push_back(t / n);
    return answer;
}