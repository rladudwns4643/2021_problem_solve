#include <iostream>
#include <queue>

using namespace std;

int main() {
	int input;
	cin >> input;
	queue<int> table;
	for (int i = 1; i <= input; ++i) {
		table.push(i);
	}
	while (table.size() != 1) {
		table.pop();
		int t = table.front();
		table.pop();
		table.push(t);
	}
	cout << table.front();
}