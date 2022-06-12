#include <iostream>
#include <queue>
using namespace std;
struct comp {
	bool operator()(int& l, int& r) {
		if (abs(l) == abs(r)) return l > r;
		return abs(l) > abs(r); 
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int, vector<int>, comp> pq;
	int n, t;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else pq.push(t);
	}
}