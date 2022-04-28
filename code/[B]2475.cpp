#include <iostream>
#include <vector>

using namespace std;

int main() {
	int ans{ 0 };
	for (int i = 0; i < 5; ++i) {
		int t;
		cin >> t;
		ans += t * t;
	}
	cout << ans%10;
}