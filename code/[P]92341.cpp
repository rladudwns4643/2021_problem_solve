#include <string>
#include <vector>
#include <map>
using namespace std;

int changeTime(string s) {
    int t = ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + ((s[3] - '0') * 10 + (s[4] - '0'));
    return t;
}

int getNumber(string s) {
    return atoi(s.substr(6, 4).c_str());
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, int> t;
    int len = records.size();

    vector<int> in_time(9999, -1);


    for (int i = 0; i < len; ++i) {
        int nowNum = getNumber(records[i]);
        int nowTime = changeTime(records[i]);
        if (records[i].length() == 13) { //in
            in_time[nowNum] = nowTime;
        }
        else {
            auto ret = t.insert({ nowNum, nowTime - in_time[nowNum] });
            if (ret.second == false) {
                t[nowNum] = ret.first->second + nowTime - in_time[nowNum];
            }
            in_time[nowNum] = -1;
        }
    }
    for (int i = 0; i < 9999; ++i) {
        if (in_time[i] != -1) {
            auto ret = t.insert({ i, changeTime("23:59") - in_time[i] });
            if (ret.second == false) {
                t[i] = ret.first->second + changeTime("23:59") - in_time[i];
            }
        }
    }

    for (const auto& a : t) {
        int useTime = a.second;
        if (fees[0] >= useTime) {
            answer.emplace_back(fees[1]);
        }
        else if (fees[0] < useTime) {
            int overTime = useTime - fees[0];
            if (overTime % fees[2] != 0) {
                answer.emplace_back(((overTime / fees[2]) + 1) * fees[3] + fees[1]);
            }
            else {
                answer.emplace_back((overTime / fees[2]) * fees[3] + fees[1]);
            }
        }
    }

    return answer;
}