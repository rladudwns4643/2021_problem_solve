#include <iostream>
#include <string>
using namespace std;

int solution(int N) {
	int six = 666;
	int cur = 0;
	string target;
	while (1) {
		target = to_string(six);
		for (int i = 0; i < target.length() - 2; ++i) {
			if (target.substr(i, 3) == "666"){
				cur++;
				if (cur == N) return six;
				else break;
			}
		}
		++six;
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	cout << solution(n);
}