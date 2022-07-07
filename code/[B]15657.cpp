#include <iostream>
#include <algorithm>
using namespace std;
constexpr int MAX{ 9 };

int N, M;
int f[MAX];
int arr[MAX];

void dfs(int num, int k) {
	if (k == M) {
		for (int i = 0; i < M; ++i) cout << arr[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = num; i < N; ++i) {
			arr[k] = f[i];
			dfs(i, k + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; ++i) cin >> f[i];
	stable_sort(f, f + N);
	dfs(0, 0);
	return 0;
}