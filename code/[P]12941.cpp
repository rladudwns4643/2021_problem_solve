#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    stable_sort(A.begin(), A.end(), [](const int& l, const int& r) {return l < r; });
    stable_sort(B.begin(), B.end(), [](const int& l, const int& r) { return l > r; });

    for (int i = 0; i < A.size(); ++i) {
        answer += A[i] * B[i];
    }
    return answer;
}