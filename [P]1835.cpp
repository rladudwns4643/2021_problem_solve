#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;



int solution(int n, vector<string> data) {
	int answer = 0;
	map<char, int> name;
	name.insert(make_pair('A', 0));
	name.insert(make_pair('C', 1));
	name.insert(make_pair('F', 2));
	name.insert(make_pair('J', 3));
	name.insert(make_pair('M', 4));
	name.insert(make_pair('N', 5));
	name.insert(make_pair('R', 6));
	name.insert(make_pair('T', 7));

	vector<int> table(8);
	for (int i = 0; i < 8; ++i) table[i] = i;

	do {
		bool success{ true };
		for (int i = 0; i < data.size(); ++i) {
			int curr1 = table[name[data[i][0]]];
			int curr2 = table[name[data[i][2]]];
			char opt = data[i][3];
			int dist = data[i][4] - '0' + 1;

			switch (opt) {
			case '=':
				if (abs(curr1 - curr2) != dist) success = false;
				break;
			case '>':
				if (abs(curr1 - curr2) <= dist) success = false;
				break;
			case '<':
				if (abs(curr1 - curr2) >= dist) success = false;
				break;
			}
		}
		answer += success;
	} while (next_permutation(table.begin(), table.end()));

	return answer;
}