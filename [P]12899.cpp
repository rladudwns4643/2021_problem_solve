#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer;
    while (n > 0) {
        int t = (n - 1) % 3;
        answer.push_back("124"[t]);
        n = (n - 1) / 3;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}