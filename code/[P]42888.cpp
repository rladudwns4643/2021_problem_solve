#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) answer.push_back(temp);
    return answer;
}

vector<string> solution(vector<string> record) {
    map<string, string> id_name;
    vector<string> answer;

    for (auto& a : record) {
        auto input = split(a, ' ');
        if (input[0] == "Enter") id_name[input[1]] = input[2];
        if (input[0] == "Change") id_name[input[1]] = input[2];
    }
    for (auto& a : record) {
        auto input = split(a, ' ');

        if (input[0] == "Enter") {
            string t = id_name[input[1]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
            answer.push_back(t);
        }
        if (input[0] == "Leave") {
            string t = id_name[input[1]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
            answer.push_back(t);
        }
    }
    return answer;
}