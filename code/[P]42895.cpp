#include <iostream>
#include <string> 
#include <vector> 
#include <algorithm>
#include <unordered_set> 
using namespace std; 
int solution(int N, int number) {
	unordered_set<int> m[9];

	for (int i = 1, j = N; i < 9; ++i, j = j * 10 + N) {
		m[i].insert(j);
	}

	for (int i = 2; i < 9; ++i) {
		for (int j = 1, k = i - 1; j <= k; ++j, --k) {
			for (const auto& l : m[j]) {
				for (const auto& r : m[k]) {
					m[i].insert(l + r);
					m[i].insert(l - r);
					m[i].insert(r - l);
					m[i].insert(l * r);
					if (l != 0) m[i].insert(r / l);
					if (r != 0) m[i].insert(l / r);
				}
			}
		}
	}

	for (int i = 1; i < 9; ++i) {
		if (m[i].find(number) != m[i].end()) return i;
	}

	return -1;
}