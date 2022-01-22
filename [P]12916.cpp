#include <string>
#include <iostream>
using namespace std;

bool solution(string s) {
    int val{ 0 };
    for (auto& a : s) {
        if (a == 'P') ++val;
        if (a == 'p') ++val;
        if (a == 'Y') --val;
        if (a == 'y') --val;
    }
    return val == 0 ? true : false;
}