#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

bool isprime(ll n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
string change(int input, int k) {
    string ret = "";
    while (input) {
        ret += to_string(input % k);
        input /= k;
    }
    return string(ret.rbegin(), ret.rend());
}
int solution(int n, int k) {
    int answer = 0;

    auto num = change(n, k);
    string t;
    for (int i = 0; i < num.length(); ++i) {
        if (num[i] == '0' && !t.empty()) {
            ll n = stoll(t);
            if (isprime(n)) ++answer;
            t = "";
        }
        else t += num[i];
    }
    if (!t.empty()) {
        ll n = stoll(t);
        if (isprime(n)) ++answer;
    }
    return answer;
}