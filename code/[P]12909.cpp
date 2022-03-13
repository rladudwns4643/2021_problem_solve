#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int cnt{ 0 };
    for (const auto& a : s) {
        if (a == '(') ++cnt;
        else --cnt;
        if (cnt < 0) return false;
    }
    if (cnt != 0) return false;
    return true;
}