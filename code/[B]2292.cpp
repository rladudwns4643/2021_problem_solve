#include <iostream>
using namespace std;
#define MAX 1'000'000'000
int main() {
	int input;
	cin >> input;
	--input;
	int i = 1;
	while (input > 0) {
		input -= (i * 6);
		++i;
	}
	cout << i << endl;
}