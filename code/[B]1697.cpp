#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 200001;
int cnt{ 0 };
queue<int> qi;
queue<int> qqi;
bool visit[MAX];

void solv(int start, int find) {
	while (qi.front() != find) {
		if (qi.front() * 2 <= MAX && !visit[qi.front() * 2]) {
			qqi.push(qi.front() * 2);
			visit[qi.front() * 2] = true;
		}
		if (qi.front() + 1 <= MAX && !visit[qi.front() + 1]) {
			qqi.push(qi.front() + 1);
			visit[qi.front() + 1] = true;
		}
		if (qi.front() - 1 >= 0 && !visit[qi.front() - 1]) {
			qqi.push(qi.front() - 1);
			visit[qi.front() - 1] = true;
		}
		qi.pop();
		if (qi.empty()) {
			qi = qqi;
			for (; !qqi.empty();) qqi.pop();
			++cnt;
		}
	}
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(visit, false, sizeof(visit));
	int n, k;
	cin >> n >> k;
	if (n == k) cout << 0;
	else {
		qi.push(n);
		solv(n, k);
	}
}