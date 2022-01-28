#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool flag = true;
    for (auto& a : s) {
        if (a != ' ') {
            if (flag) a = toupper(a);
            else a = tolower(a);
            flag = !flag;
        }
        else flag = true;
        answer += a;
    }

    return answer;
}