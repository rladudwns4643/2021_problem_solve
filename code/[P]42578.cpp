#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> tp;

    for (int i = 0; i < clothes.size(); ++i) {
        tp[clothes[i][1]]++;
    }

    for (const auto& t : tp) {
        answer *= (t.second + 1);
    }

    return answer - 1;
}