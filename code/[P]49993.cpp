#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, int> skills;
    for (int i = 0; i < skill.size(); ++i) {
        skills[skill[i]] = i + 1;
    }

    for (const string& s : skill_trees) {
        int cnt{ 1 };
        bool flag{ true };
        for (const char& c : s) {
            if (skills[c] > cnt) {
                flag = false;
                break;
            }
            else if (skills[c] == cnt) {
                ++cnt;
            }
        }
        if (flag) ++answer;
    }

    return answer;
}