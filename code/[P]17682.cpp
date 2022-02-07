#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int cur{ -1 };
    int cur_num{ 0 };
    int prev_num{ 0 };
    while (++cur < dartResult.size()) {
        if (isdigit(dartResult[cur])) {
            answer += prev_num;
            prev_num = cur_num;
            if (dartResult[cur + 1] == '0') {
                cur_num = 10;
                cur++;
                continue;
            }
            cur_num = dartResult[cur] - '0';
            continue;
        }
        switch (dartResult[cur]) {
        case 'S': {
            cur_num = pow(cur_num, 1);
            break;
        }
        case 'D': {
            cur_num = pow(cur_num, 2);
            break;
        }
        case 'T': {
            cur_num = pow(cur_num, 3);
            break;
        }
        case '*': {
            cur_num *= 2;
            prev_num *= 2;
            break;
        }
        case '#': {
            cur_num = cur_num * -1;
            break;
        }
        }
    }
    answer += cur_num;
    answer += prev_num;

    return answer;
}