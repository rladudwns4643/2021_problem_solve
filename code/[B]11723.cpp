#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool table[21];
    int M, num;
    string input;

    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> input;

        if (input == "add") {
            cin >> num;
            table[num] = true;
        }
        else if (input == "remove") {
            cin >> num;
            table[num] = false;
        }
        else if (input == "check") {
            cin >> num;
            table[num] == 1 ? cout << "1\n" : cout << "0\n";
        }
        else if (input == "toggle") {
            cin >> num;
            table[num] == 0 ? table[num] = 1 : table[num] = 0;
        }
        else if (input == "all") {
            fill(table, table + 21, 1);
        }
        else if (input == "empty") {
            fill(table, table + 21, 0);
        }
    }
}