#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> t;
    for (int i = 0; i < s.size(); ++i) {
        if (!t.empty() && t.top() == s[i]) t.pop();
        else t.push(s[i]);
    }
    return t.size() == 0 ? 1 : 0;
}