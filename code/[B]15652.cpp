#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
bool visit[10];

void dfs(int num, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; ++i) cout << arr[i] << ' ';
		cout << "\n";
		return;
	}
	for (int i = num; i <= n; ++i) {
		visit[i] = true;
		arr[cnt] = i;
		dfs(i, cnt + 1);
		visit[i] = false;
	}
}

int main() {
	memset(&visit, false, sizeof(visit));
	memset(&arr, 0, sizeof(arr));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	dfs(1, 0);
}