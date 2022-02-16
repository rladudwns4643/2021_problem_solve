#include <string>
#include <vector>
#include <stack>
using namespace std;

bool check(string b) {
    stack<char> st;
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] == '(') {
            st.push(b[i]);
        }
        else if (b[i] == ')') {
            if (st.empty()) return false;
            else {
                st.pop();
            }
        }
    }
    return st.empty() == true ? true : false;
}

string change(string p) {
    if (p == "") return p;

    string u = "";
    string v = "";

    int left = 0;
    int right = 0;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] == '(') ++left;
        if (p[i] == ')') ++right;
        if (left == right) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if (check(u)) return u + change(v);
    else {
        string ret = "(" + change(v) + ")";
        u = u.substr(1, u.size() - 2);
        for (int i = 0; i < u.size(); ++i) {
            if (u[i] == '(') u[i] = ')';
            else if (u[i] == ')') u[i] = '(';
        }
        return ret + u;
    }
}

string solution(string p) {
    if (check(p)) return p;
    return change(p);
}