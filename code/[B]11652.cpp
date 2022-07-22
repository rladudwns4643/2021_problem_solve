#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

int main() {
	ll n, num;
	map<ll, int> m;
	cin >> n;
	while (n--) {
		cin >> num;
		m[num]++;
	}
	int max = 0;
	ll ans = 0;
	for (const auto& a : m) {
		if (a.second > max) {
			max = a.second;
			ans = a.first;
		}
	}
	cout << ans;
}