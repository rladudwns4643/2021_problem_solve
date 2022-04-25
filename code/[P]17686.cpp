#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

char to_lower(char c) {
	if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
	return c;
}

int num_start(const string& str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			return i;
		}
	}
	return -1;
}
string get_head(string str) {
	string ret = str.substr(0, num_start(str));
	transform(ret.begin(), ret.end(), ret.begin(), to_lower);
	return ret;
}

vector<string> solution(vector<string> files)
{
	stable_sort(files.begin(), files.end(), [](const string& l, const string& r) {
		return stoi(l.substr(num_start(l))) < stoi(r.substr(num_start(r)));
		});

	stable_sort(files.begin(), files.end(), [](const string& l, const string& r) {
		return get_head(l).compare(get_head(r)) < 0;
		});

	return files;
}