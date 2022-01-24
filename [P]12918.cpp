#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if (s.length() != 4 && s.length() != 6) return false;
    for (auto& a : s) {
        //isdigit(a);
        if (!(a >= '0' && a <= '9'))
            return false;
    }
    return true;
}