#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

// enter_len�� �迭 enter�� �����Դϴ�.
// leave_len�� �迭 leave�� �����Դϴ�.
int* solution(int enter[], size_t enter_len, int leave[], size_t leave_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    
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