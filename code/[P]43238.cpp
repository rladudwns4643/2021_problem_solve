#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ���� �־��� �ð����� �ɻ�븦 �� �� ������ �� �ִ°�?
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
    long long end = times[times.size() - 1] * (long long)n;     //���� �� �ð� * �ο���
    long long answer = end, mid = 0;

    while (start <= end) {
        mid = (start + end) / 2;                //�߰�
        if (findN(mid, times) < n) {            //�߰��� �������� ������ �ο��� �߰� ���� �ο��� �����ϸ�
            start = mid + 1;                    //�������� �߰� �ڷ� �̵�
        }
        else {                                  //�߰��� �������� ������ �ο��� �߰� ���� �ο��� �Ѵ´ٸ� 
            if (mid <= answer) answer = mid;    //�߰��� ���� �亸�� ������� ���ο� �߰��� ��
            end = mid - 1;                      //���� �߰�����
        }
    }
    return answer;
}

int main() {
    solution(6, { 7,10 });
}