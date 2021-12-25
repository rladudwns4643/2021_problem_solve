#include <iostream>
#include <string>
using namespace std;

int val[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };

int main() {
	string ss;
	cin >> ss;

	int total{ 0 };
	for (const char& c : ss) total += (val[c - 'A']);

	cout << total;
}