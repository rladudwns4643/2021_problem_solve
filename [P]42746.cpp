#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) { //가장 큰 수 - success
	string answer = "";
	vector<string> tmp;

	for (auto& n : numbers) tmp.emplace_back(to_string(n));

	sort(tmp.begin(), tmp.end(), [](const string& s1, const string& s2) {
		return s1 + s2 > s2 + s1;
		});

	for (auto& a : tmp) answer += a;

	if (answer[0] == '0') return "0";

	return answer;
}