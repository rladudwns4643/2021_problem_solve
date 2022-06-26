#include <iostream>
using namespace std;

int n, s; 
int arr[30];
int cnt{ 0 };

void solution(int cur, int tot) {
	if (cur == n) {
		if (tot == s) cnt++;
		return;
	}
	solution(cur + 1, tot);
	solution(cur + 1, tot + arr[cur]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	solution(0, 0);
	if (s == 0) cnt--;
	cout << cnt;
}