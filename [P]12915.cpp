#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end());
    stable_sort(strings.begin(), strings.end(), [n](const string& rhs, const string& lhs) {
        return rhs[n] < lhs[n];
        });

    return strings;
}