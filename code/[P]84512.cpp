#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string word) {
    int answer = 0;
    int max = 0;
    for (int i = 1; i <= 5; ++i) {
        max += pow(5, i);
    }
    for (int i = 1; i <= word.size(); ++i) {
        if (word[i - 1] == 'A') answer += 1;
        else if (word[i - 1] == 'E') answer += ((max / pow(5, i)) * 1) + 1;
        else if (word[i - 1] == 'I') answer += ((max / pow(5, i)) * 2) + 1;
        else if (word[i - 1] == 'O') answer += ((max / pow(5, i)) * 3) + 1;
        else if (word[i - 1] == 'U') answer += ((max / pow(5, i)) * 4) + 1;
    }
    return answer;
}