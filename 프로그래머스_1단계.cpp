//1¹ø

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if (a == b) return a;
    int high = max(a, b);
    int low = b;
    if (high == b) low = a;
    for (int i = low; i <= high; ++i) {
        answer += i;
    }

    return answer;
}

//2¹ø

#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    vector<int> sq(1025);
    sq[1] = true;
    for (int i = 2; i < 33; ++i) {
        sq[i * i] = true;
    }

    for (int i = left; i <= right; ++i) {
        if (sq[i] == true) answer -= i;
        else answer += i;
    }

    return answer;
}