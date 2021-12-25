#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int time[17] = { 0, };
    int pay[17] = { 0, };
    int n, i;
    int ans = 0;

    cin >> n;

    for (i = 1; i <= n; i++) cin >> time[i] >> pay[i];

    for (i = n; i >= 1; i--) {
        if (i + time[i] > n + 1) pay[i] = pay[i + 1];
        else {
            pay[i] = max(pay[i + 1], pay[i] + pay[i + time[i]]);
            ans = max(ans, pay[i]);
        }
    }

    cout << ans << endl;

    return 0;
}