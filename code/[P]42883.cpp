#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

string solution(string number, int k) {
	string answer{ "" };
	stack<char> sc;

	for (int i = 0; i < number.length(); ++i) {
		char cur = number[i];
		while (!sc.empty() && k > 0) {
			char top = sc.top();
			if (top < cur) {
				sc.pop();
				--k;
			}
			else break;
		}
		sc.push(cur);
	}
	for (int i = 0; i < k; ++i) {
		sc.pop();
	}
	while (!sc.empty()) {
		answer += sc.top();
		sc.pop();
	}
	reverse(answer.begin(), answer.end());

	return answer;
}