#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    int cur{ 0 };
    int len{ static_cast<int>(words.size()) };
    vector<string> table;
    table.reserve(len);
    table.push_back(words[cur]);
    while (cur < len - 1) {
        if (find(table.begin(), table.end(), words[cur + 1]) != table.end()
            || words[cur].back() != words[cur + 1].front()) {
            return { ((cur + 1) % n) + 1 , ((cur + 1) / n) + 1 };
        }
        else {
            table.push_back(words[cur + 1]);
            ++cur;
        }
    }
    return { 0,0 };
}