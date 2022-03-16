#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int nums = 1;
    int sum = 0;
    while (sum < n) {
        sum = 0;
        for (int i = 1; i <= nums; ++i) sum += i;
        if ((n - sum) % nums == 0) ++answer;
        ++nums;
    }
    return answer;
}