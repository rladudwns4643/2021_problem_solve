#include <iostream>
using namespace std;
bool isuse1[40]; //열
bool isuse2[40]; //좌하~우상 대각
bool isuse3[40]; //좌상~우하 대각

int cnt{ 0 };
int n;
void solution(int cur) {
	if (cur == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (isuse1[i] || isuse2[i + cur] || isuse3[cur - i + n - 1]) continue;
		isuse1[i] = true;
		isuse2[i + cur] = true;
		isuse3[cur - i + n - 1] = true;
		solution(cur + 1);
		isuse1[i] = false;
		isuse2[i + cur] = false;
		isuse3[cur - i + n - 1] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	solution(0);
	cout << cnt;
}