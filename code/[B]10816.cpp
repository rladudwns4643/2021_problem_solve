#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int input;

	cin >> input;
	map<int, int> table;
	for (int i = 0; i < input; ++i) {
		int t;
		cin >> t;
		table[t]++;
	}

	cin >> input;
	for (int i = 0; i < input; ++i) {
		int t;
		cin >> t;
		cout << table[t] << " ";
	}
	return 0;
}