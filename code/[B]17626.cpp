#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> memo(n + 1, 0);
	memo[1] = 1;
	
	for (int i = 2; i <= n; ++i) {
		int low = 987654321;
		for (int j = 1; j * j <= i; ++j) {
			int tmp = i - j * j;
			low = min(low, memo[tmp]);
		}
		memo[i] = low + 1;
	}
	cout << memo[n];
}