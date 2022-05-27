#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, m, ans = 0;
    string word;
    cin >> n >> m >> word;
    int word_size = word.size();
    for (int i = 0; i < word_size; i++) {
        int cnt = 0;
        if (word[i] == 'O') continue;
        while (word[i + 1] == 'O' && word[i + 2] == 'I') {
            i += 2;
            cnt++;
            if (cnt == n) { cnt--; ans++; }
        }
    }
    cout << ans << '\n';
}