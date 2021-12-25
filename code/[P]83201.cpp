#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";

    int len = scores.size();
    int max, min;
    float total = 0;
    for (int i = 0; i < len; ++i) {
        max = -1;
        min = 101;
        total = 0;
        for (int j = 0; j < len; ++j) {
            int& t = scores[j][i];
            if (j != i) {
                if (max < t) max = t;
                if (min > t) min = t;
            }
            total += t;
        }

        if (min > scores[i][i] || max < scores[i][i]) {
            total = (total- scores[i][i]) / (len-1);
        }
        else {
            total = total / len;
        }
        if (total >= 90) answer += "A";
        else if (total >= 80) answer += "B";
        else if (total >= 70) answer += "C";
        else if (total >= 50) answer += "D";
        else answer += "F";
    }

    return answer;
}