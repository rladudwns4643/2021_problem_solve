#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());
    for (auto& a : citations) {
        cout << a << " ";
    }
    for (int i = 0; i < citations.size(); ++i) {
        int cnt{ 0 };
        if (citations[i] == 0) continue;
        for (int j = i; j < citations.size(); ++j) {
            if (citations[i] <= citations[j])cnt++;
        }
        if (cnt > citations[i]) cnt = citations[i];
        if (answer < cnt) answer = cnt;
    }
    return answer;
}