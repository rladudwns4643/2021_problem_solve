#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	vector<int> vi(26);

	string tmp;
	cin >> tmp;
	//97 122
	int i;
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);

	for (char ch : tmp) {
		i = (int)ch - 65;		//65 ~ 90
		++vi[i];
	}
	auto m = max_element(vi.begin(), vi.end());

	char c = (char)(m - vi.begin() + 65);
	int val = *m;
	vi.erase(m);
	if (find(vi.begin(), vi.end(), val) == vi.end()) cout << c << endl;
	else cout << "?" << endl;
}