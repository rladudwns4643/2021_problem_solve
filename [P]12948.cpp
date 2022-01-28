#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int cur = phone_number.size() - 4;
    string answer(cur, '*');
    for (int i = 0; i < 4; ++i) {
        answer += *(phone_number.begin() + cur + i);
    }
    return answer;
}