#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int cnt{ 0 };
    long long NUM = num;
    while (++cnt) {
        if (NUM == 1) {
            cnt--;
            break;
        }
        if (NUM % 2 == 0) NUM /= 2;
        else NUM = (NUM * 3) + 1;
    }

    return cnt >= 500 ? -1 : cnt;
}