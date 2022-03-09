#include <string>
#include <vector>

using namespace std;

typedef long long ll;

ll change(ll num) {
    if (num % 2 == 0) return num + 1;
    ll cnt = 1;
    while (1) {
        if ((num & cnt) == 0) break;
        cnt *= 2;
    }
    cnt /= 2;
    return num + cnt;
}

vector<long long> solution(vector<long long> numbers) {
    vector<ll> answer;
    for (const auto& a : numbers) {
        answer.push_back(change(a));
    }
    return answer;
}