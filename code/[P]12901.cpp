#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<int> month{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    vector<string> day{ "THU", "FRI","SAT", "SUN", "MON", "TUE", "WED" };

    int t{ b };
    for (int i = 0; i < a - 1; ++i) {
        t += month[i];
    }
    t = t % 7;
    return day[t];
}