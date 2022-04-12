#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    map<string, vector<int>> info_score;

    for (const string& str : info) {
        vector<string> t(4);
        stringstream ss(str);
        for (auto& a : t) {
            ss >> a;
        }
        int score;
        ss >> score;

        for (int i = 0; i <= 4; ++i) {
            string s1(i, '0');
            string s2(4 - i, '1');
            string condi = s1 + s2;
            do {
                string s3 = "";
                for (int j = 0; j < 4; ++j) {
                    if (condi[j] == '0') s3 += t[j];
                    else s3 += '-';
                }
                info_score[s3].emplace_back(score);
            } while (next_permutation(condi.begin(), condi.end()));
        }
    }
    for (auto& a : info_score) {
        stable_sort(a.second.begin(), a.second.end());
    }

    for (string& str : query) {
        int score;
        string key;
        stringstream ss(str);
        for (int i = 0; i < 7; ++i) {
            string t;
            ss >> t;
            if(!(i&1)) key += t; //짝수라면 추가(and 넘기기)
        }
        ss >> score;
        vector<int> scores = info_score[key];

        int index = lower_bound(scores.begin(), scores.end(), score) - scores.begin();
        answer.emplace_back(scores.size() - index);
    }
    return answer;
}