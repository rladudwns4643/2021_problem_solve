#include <iostream>
#include <numeric>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	int table[(int)1e5];
	int n = 0;
	while (cnt--) {
		cin >> table[n];
		if (table[n]) ++n;
		else --n;
	}
	cout << (int)accumulate(table, table + n, 0);
}