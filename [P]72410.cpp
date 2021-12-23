#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for (int k = 0; k < new_id.length(); k++)
        if (new_id[k] >= 'A' && new_id[k] <= 'Z')
            new_id[k] |= 32;

    for (int k = 0; k < new_id.length(); k++) {
        if ((new_id[k] >= 'a' && new_id[k] <= 'z') ||
            (new_id[k] >= '0' && new_id[k] <= '9') ||
            (new_id[k] == '-' || new_id[k] == '_' || new_id[k] == '.'))
            answer += new_id[k];
    }

    for (int k = 1; k < answer.length(); k++) {
        if (answer[k - 1] == '.' && answer[k] == '.') {
            answer.erase(k, 1);
            k--;
        }
    }

    if (answer[0] == '.') answer.erase(0, 1);
    if (answer[answer.length() - 1] == '.') answer.erase(answer.length() - 1, 1);
    if (answer == "") answer += 'a';
    if (answer.length() >= 16) answer.erase(15);
    if (answer[answer.length() - 1] == '.') answer.erase(answer.length() - 1, 1);

    if (answer.length() <= 2) {
        char lastChar = answer[answer.length() - 1];
        for (int k = answer.length(); k < 3; k++) answer += lastChar;
    }

    return answer;
}