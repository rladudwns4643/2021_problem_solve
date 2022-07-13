#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int N;
vector<ll> answer = { 0,1,2 };
constexpr int sp{ 15746 };
void solution() {
    long long tmp;
    for (int i = 3; i <= N; i++) {
        tmp = 0;
        tmp = answer[i - 1] + answer[i - 2];
        answer.push_back(tmp % sp);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    solution();
    cout << answer[N] % sp;
}