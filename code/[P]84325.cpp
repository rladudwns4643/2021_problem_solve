#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    string tmp;
    int num, cnt, max, idx;
    vector<int> score;
    vector<vector<string>> arr(5, vector<string>(0));
    for (int i = 0; i < table.size(); i++) {
        stringstream ss(table[i]);
        while (getline(ss, tmp, ' ')) {
            arr[i].push_back(tmp);
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        cnt = 0;
        num = 0;
        for (int j = 1; j < arr[0].size(); j++) {
            for (int k = 0; k < languages.size(); k++) {
                if (languages[k] == arr[i][j]) {
                    num += (6 - j) * preference[k];
                    cnt++;
                }
            }
        }
        score.push_back(num);
    }
    max = 0;
    for (int i = 0; i < score.size(); i++) {
        if (max < score[i]) {
            max = score[i];
            idx = i;
        }
        else if (max == score[i]) {
            if (arr[i][0] < arr[idx][0]) {
                max = score[i];
                idx = i;
            }
        }
    }
    answer = arr[idx][0];
    return answer;
}