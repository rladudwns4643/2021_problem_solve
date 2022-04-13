#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dp[60001];

int memo(int n) {
    if (n == 1 || n == 2) return n;
    if (dp[n] != 0) return dp[n];
    dp[n] = (memo(n - 1) + memo(n - 2)) % 1000000007;
    return dp[n];
}

int solution(int n) {
    fill(dp, dp + 60001, 0);
    return memo(n);
}