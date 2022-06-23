#include <iostream>
using namespace std;
constexpr int MAX = 8;
int N, M;

int store[MAX];
int visit[MAX + 1];

void dfs(int phase) {
    if (phase == M) {
        for (int i = 0; i < M; i++) {
            cout << store[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visit[i] == false) {
            visit[i] = true;
            store[phase] = i;
            dfs(phase + 1);
            visit[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
    return 0;
}