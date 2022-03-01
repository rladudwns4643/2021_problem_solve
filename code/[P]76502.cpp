#include <string>
#include <vector>
#include <stack>
using namespace std;

string rotate(string s) {
	string ret = s;
	char t = ret[0];
	ret.erase(0, 1);
	ret.push_back(t);
	return ret;
}

bool isCorrect(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
		else {
			if (st.empty()) return false;
			if (st.top() == '(' && s[i] == ')') {
				st.pop();
				continue;
			}
			if (st.top() == '{' && s[i] == '}') {
				st.pop();
				continue;
			}
			if (st.top() == '[' && s[i] == ']') {
				st.pop();
				continue;
			}
		}
	}
	if (!st.empty()) return false;
	return true;
}

int solution(string s) {
	int answer = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (isCorrect(s)) ++answer;
		s = rotate(s);
	}
	return answer;
}