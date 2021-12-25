#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int N, M;
	set<int> know;

	cin >> N >> M;
	int k{ 0 };
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int t{ 0 };
		cin >> t;
		know.insert(t);
	}
	vector<int> party[50];
	for (int i = 0; i < M; ++i) {
		int t{ 0 };
		cin >> t;
		for (int j = 0; j < t; ++j) {
			int partyer;
			cin >> partyer;
			party[i].emplace_back(partyer);
		}
	}
	auto know_len{ know.size() };
	for (int i = 0; i < M; ++i) {
		bool flag{ false };
		for (auto& a : party[i]) {
			if (find(know.begin(), know.end(), a) != know.end()) {
				for (auto& b : party[i]) {
					if (know.insert(b).second == true) {
						i = -1;
						flag = true;
						break;
					}
				}
				if (flag) { break; }
			}
		}
	}
	int ret{ M };
	for (int i = 0; i < M; ++i) {
		for (auto& a : party[i]) {
			if (find(know.begin(), know.end(), a) != know.end()) {
				--ret;
				break;
			}
		}
	}

	cout << ret;
}