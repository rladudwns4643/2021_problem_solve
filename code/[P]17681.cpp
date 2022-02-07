#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string tentotwo(int input, int n) {
    string t;
    while (!(input == 0 || input == 1)) {
        if (input % 2 == 1) {
            t += '1';
        }
        else {
            t += '0';
        }
        input /= 2;
    }
    t += to_string(input);
    while (t.length() < n) t += '0';
    reverse(t.begin(), t.end());
    return t;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    answer.resize(n);
    for (int i = 0; i < n; ++i) {
        string a = tentotwo(arr1[i], n);
        string b = tentotwo(arr2[i], n);
        for (int j = 0; j < n; ++j) {
            if (a[j] == '1' || b[j] == '1') answer[i].push_back('#');
            else answer[i].push_back(' ');
        }
    }
    return answer;
}