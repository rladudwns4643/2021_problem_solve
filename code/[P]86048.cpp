#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

// enter_len은 배열 enter의 길이입니다.
// leave_len은 배열 leave의 길이입니다.
int* solution(int enter[], size_t enter_len, int leave[], size_t leave_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    int* answer = (int*)malloc(enter_len * sizeof(int));
    int* room = (int*)malloc((enter_len+1) * sizeof(int));
    memset(answer, 0, enter_len * sizeof(int));
    memset(room, 0, (enter_len + 1) * sizeof(int));
    int cur = 0;
    int cnt = 0;
    for (int i = 0; i < enter_len; ++i) {
        for (int j = 1; j <= enter_len; ++j) {
            if (room[j] > 0) room[j]++;
        }
        cnt++;
        room[enter[i]] = cnt;
        while (cur != leave_len) {
            if (room[leave[cur]] > 0) {
                answer[leave[cur]-1] = room[leave[cur]] - 1;
                room[leave[cur]] = 0;
                cur++;
                cnt--;
            }
            else {
                break;
            }
        }
    }
    return answer;
}