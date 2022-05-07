#include <iostream>
using namespace std;

int n, m, table[1000000];
bool check(const int& mid) {
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		if (table[i] > mid) sum += table[i] - mid;
	}
	return sum >= m;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> table[i];
	int low = 0, high = INT64_MAX;
	while (low + 1 < high) {
		int mid = (low + high) / 2;
		if (check(mid)) low = mid;
		else high = mid;
	}
	cout << low << "\n";
	return 0;
}