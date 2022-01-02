#include <regex>
#include <string>
#include <vector>

using namespace std;
int solution(string s) {
    vector<string> patterns = { "zero","one","two","three","four","five","six","seven","eight","nine" };
    string num = "0123456789";
    for (int i = 0; i < num.size(); i++) {
        s = regex_replace(s, regex(patterns[i]), num.substr(i, 1));
    }
    return stoi(s);
}