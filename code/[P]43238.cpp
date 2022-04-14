#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 현재 주어진 시간에서 심사대를 몇 명 지나갈 수 있는가?
long long findN(long long ref, vector<int> times) {
    long long n = 0;
    for (int i = 0; i < times.size(); i++) {
        n += ref / times[i];
    }
    return n;
}

long long solution(int n, vector<int> times) {
    stable_sort(times.begin(), times.end());

    long long start = 0;
    long long end = times[times.size() - 1] * (long long)n;     //제일 긴 시간 * 인원수
    long long answer = end, mid = 0;

    while (start <= end) {
        mid = (start + end) / 2;                //중간
        if (findN(mid, times) < n) {            //중간을 기준으로 지나간 인원이 중간 기준 인원이 부족하면
            start = mid + 1;                    //시작점을 중간 뒤로 이동
        }
        else {                                  //중간을 기준으로 지나간 인원이 중간 기준 인원이 넘는다면 
            if (mid <= answer) answer = mid;    //중간이 기존 답보다 적을경우 새로운 중간이 답
            end = mid - 1;                      //끝을 중간으로
        }
    }
    return answer;
}

int main() {
    solution(6, { 7,10 });
}