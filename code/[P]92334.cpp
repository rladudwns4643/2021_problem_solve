#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    map<string, int> table;
    map<string, set<string>> report_table;

    for (auto& a : id_list) {
        table.insert(make_pair(a, 0));
    }

    for (auto& a : report) {
        string reporter;
        string reported;
        auto it = find(a.begin(), a.end(), ' ');
        auto reporter_it = a.begin();
        while (reporter_it != it) {
            reporter += *reporter_it;
            reporter_it++;
        }
        while (it != a.end()) {
            reported += *it;
            it++;
        }
        if (report_table[reporter].find(reported) == report_table[reporter].end()) {
            table[reported]++;
            report_table[reporter].insert(reported);
        }
    }

    for (auto& a : id_list) {
        int t = 0;
        for (auto it = report_table[a].begin(); it != report_table[a].end(); ++it) {
            if (table[*it] >= k) ++t;
        }
        answer.push_back(t);
    }

    return answer;
}