#include <bits/stdc++.h>

using namespace std;
multiset<string> st1;
multiset<string> st2;
int solution(string s1, string s2) {
    for (int i = 0; i < s1.length() - 1; i++) {
        char f = tolower(s1[i]);
        char s = tolower(s1[i + 1]);
        if ('a' <= f && f <= 'z' && 'a' <= s && s <= 'z') {
            string t{ f };
            t += s;
            st1.insert(t);
        }
    }
    for (int i = 0; i < s2.length() - 1; i++) {
        char f = tolower(s2[i]);
        char s = tolower(s2[i + 1]);
        if ('a' <= f && f <= 'z' && 'a' <= s && s <= 'z') {
            string t{ f };
            t += s;
            st2.insert(t);
        }
    }
    int ans = 0, up = 0, down = st1.size() + st2.size();
    if (down == 0) return 65536;

    for (auto& i : st1) {
        int res1 = st1.count(i);
        int res2 = st2.count(i);
        up += min(res1, res2);
        if (res2 > 0) st2.erase(i);
    }
    down -= up;
    return 65536 * ((double)up / (double)down);
}