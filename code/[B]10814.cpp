#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, string> pis;
int main() {
	int input;
	cin >> input;
	vector<pis> table;
	table.reserve(input);
	for (int i = 0; i < input; ++i) {
		int age;
		string name;
		cin >> age >> name;
		table.emplace_back(make_pair(age, name));
	}
	stable_sort(table.begin(), table.end(), [](const pis& l, const pis& r) {
		return l.first < r.first;
		});

	for (const auto& a : table) {
		cout << a.first << " " << a.second << "\n";
	}
}