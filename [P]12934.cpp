#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    auto t{ sqrt(n) };
    return t / 1.00 == (int)t ? powl(t + 1, 2) : -1;
}