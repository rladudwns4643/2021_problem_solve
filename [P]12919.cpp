#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    int idx = distance(seoul.begin(), find(seoul.begin(), seoul.end(), "Kim"));
    answer += "김서방은 ";
    answer += to_string(idx);
    answer += "에 있다";
    return answer;
}