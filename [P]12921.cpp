#include <string>
#include <vector>
#include <cmath>

using namespace std;

constexpr int MAX = 1000000;
bool prime[1000001];

void make_prime() {
    prime[0] = true;
    prime[1] = true;
    for (int i = 2; i <= sqrt(MAX); ++i) {
        if (prime[i]) continue;
        for (int j = 2 * i; j <= MAX; j += i) {
            prime[j] = true;
        }
    }
}

int solution(int n) {
    int answer = 0;
    make_prime();
    for (int i = 0; i <= n; ++i) {
        if (prime[i] == false) ++answer;
    }

    return answer;
}