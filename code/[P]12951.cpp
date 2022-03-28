#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string a = "";

	a += toupper(s[0]);
	for (int i = 1; i < s.size(); ++i) {
		s[i - 1] == ' ' ? a += toupper(s[i]) : a += tolower(s[i]);
	}
	return a;
}