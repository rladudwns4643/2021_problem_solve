#include <iostream>
using namespace std;
int n;
typedef pair<int, int> pii;
pii edge[26];

void pre(char c) { //root l r
	if (c == '.') return;
	cout << c;
	pre(edge[c - 'A'].first);
	pre(edge[c - 'A'].second);
}

void in(char c) { //l root r
	if (c == '.') return;
	in(edge[c - 'A'].first);
	cout << c;
	in(edge[c - 'A'].second);
}

void post(char c) { //l r root
	if (c == '.') return;
	post(edge[c - 'A'].first);
	post(edge[c - 'A'].second);
	cout << c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char cur, left, right;
		cin >> cur >> left >> right;
		edge[cur - 'A'].first = left;
		edge[cur - 'A'].second = right;
	}
	pre('A');
	cout << "\n";
	in('A');
	cout << "\n";
	post('A');
	return 0;
}