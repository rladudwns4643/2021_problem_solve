#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int n, k;
vector<int> table;
set<int> numbers;
bool check[11];

void solution(int cnt, string s) {
	if (cnt == k) {
		numbers.insert(stoi(s));
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (check[i] == true) continue;
		check[i] = true;
		string after = s;
		after += to_string(table[i]);
		solution(cnt + 1, after);
		check[i] = false;
	}
}

int main() {
	cin >> n >> k;
	table.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> table[i];
	}

	solution(0, "");

	cout << numbers.size();
}