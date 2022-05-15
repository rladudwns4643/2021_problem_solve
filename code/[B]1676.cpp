#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int input;
	cin >> input;
	cout << (int)(input / pow(5,1)) + (int)(input / pow(5,2)) + (int)(input / pow(5,3)) << '\n';
}