#include <iostream>
using namespace std;

long long dp[101];

void memo() {
	fill(&dp[0], &dp[101], 0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 2;
	for (int i = 5; i < 101; ++i) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memo();
	int input;
	cin >> input;

	for (int i = 0; i < input; ++i) {
		int t;
		cin >> t;
		cout << dp[t - 1] << "\n";
	}
}