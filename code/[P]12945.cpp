#include <string>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
ll table[100000];

int solution(int n) {
    memset(table, 0, sizeof(table));
    table[0] = 0;
    table[1] = 1;
    for (int i = 2; i < 100001; ++i) {
        table[i] = ((table[i - 1] % 1234567) + (table[i - 2] % 1234567)) % 1234567;
    }

    return table[n];
}