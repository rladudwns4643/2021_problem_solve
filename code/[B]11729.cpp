#include <iostream>
#include <cmath>

using namespace std;

void solution(int n, int from, int t, int to) {
	if (n == 1) {
		cout << from << " " << to << "\n";
	}
	else {
		solution(n - 1, from, to, t);
		cout << from << " " << to << "\n";
		solution(n - 1, t, from, to);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << (int)pow(2, n) - 1 << "\n";
	solution(n, 1, 2, 3);

	return 0;
}