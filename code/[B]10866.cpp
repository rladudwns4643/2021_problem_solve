#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(int argc, char** argv) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dqi;
	int N;

	cin >> N;

	while (N--) {
		string str;
		cin >> str;

		if (str == "push_front") {
			int X;
			cin >> X;
			dqi.push_front(X);
		}

		else if (str == "push_back") {
			int X;
			cin >> X;
			dqi.push_back(X);
		}

		else if (str == "pop_front") {
			if (!dqi.empty()) {
				cout << dqi.front() << "\n";
				dqi.pop_front();
			}
			else
				cout << "-1\n";
		}

		else if (str == "pop_back") {
			if (!dqi.empty()) {
				cout << dqi.back() << "\n";
				dqi.pop_back();
			}
			else
				cout << "-1\n";
		}

		else if (str == "size") {
			cout << dqi.size() << "\n";
		}

		else if (str == "empty") {
			cout << dqi.empty() << "\n";
		}

		else if (str == "front") {
			if (!dqi.empty()) {
				cout << dqi.front() << "\n";
			}
			else
				cout << "-1\n";
		}

		else if (str == "back") {
			if (!dqi.empty()) {
				cout << dqi.back() << "\n";
			}
			else
				cout << "-1\n";
		}
	}
	return 0;
}