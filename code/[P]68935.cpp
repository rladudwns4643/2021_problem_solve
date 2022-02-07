#include <string>
#include <vector>
#include <math.h>

using namespace std;

string tentothree(int n) {
    string ret;
    while (n > 0) {
        char t = (n % 3) + '0';
        ret += t;
        n /= 3;
    }
    return ret;
}

int threetoten(string s) {
    int ret{ 0 };
    int t{ 0 };
    for (int i = s.length() - 1; i >= 0; i--, t++) {
        int n = s[i] - '0';
        int v = pow(3, t) * n;
        ret += v;
    }
    return ret;
}
int solution(int n) {
    int answer = 0;

    string three = tentothree(n);
    answer = threetoten(three);
    return answer;
}