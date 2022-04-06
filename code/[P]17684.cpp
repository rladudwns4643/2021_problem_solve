#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> table;
    int num = 1;
    for (; num < 27; ++num) {
        table[string{ char('@' + num) }] = num;
    }

    while (msg.size() != 0) {
        for (int i = 1; i <= msg.size(); ++i) {
            string s = msg.substr(0, i);
            if (table[s] == 0) { //fail
                table[s] = num;
                num++;
                answer.emplace_back(table[s.substr(0, i - 1)]);
                msg = msg.substr(i - 1, msg.size() - (s.size() - 1));
                break;
            }
            else { //hit
                if (msg.size() == i) {
                    answer.emplace_back(table[msg]);
                    msg = "";
                }
            }
        }
    }
    return answer;
}