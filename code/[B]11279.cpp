#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	auto comp = [](const int& l, const int& r) { return l < r; };
	priority_queue<int, vector<int>, decltype(comp)> q(comp);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		if (t != 0) q.push(t);
		else {
			if (q.empty()) cout << "0\n";
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
	}
}