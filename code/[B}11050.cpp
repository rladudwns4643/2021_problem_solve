#include <iostream>
using namespace std;
typedef long long ll;

ll pec(int input) {
	ll ret = 1;
	for (int i = 1; i <= input; ++i) {
		ret *= i;
	}
	return ret;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << pec(n) / (pec(k) * pec(n - k)) << endl;
}