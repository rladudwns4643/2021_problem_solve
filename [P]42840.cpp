#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    answer.reserve(3);
    vector<int> score{ 0,0,0 };

    vector<int> pattonA{ 1,2,3,4,5 };
    vector<int> pattonB{ 2,1,2,3,2,4,2,5 };
    vector<int> pattonC{ 3,3,1,1,2,2,4,4,5,5 };
    auto lenA{ pattonA.size() };
    auto lenB{ pattonB.size() };
    auto lenC{ pattonC.size() };
    auto len{ answers.size() };

    for (int i = 0; i < len; ++i) {
        if (pattonA[i % lenA] == answers[i]) score[0]++;
        if (pattonB[i % lenB] == answers[i]) score[1]++;
        if (pattonC[i % lenC] == answers[i]) score[2]++;
    }

    auto max = *max_element(score.begin(), score.end());

    for (int i = 0; i < 3; ++i) {
        if (score[i] == max) answer.emplace_back(i + 1);
    }

    return answer;
}