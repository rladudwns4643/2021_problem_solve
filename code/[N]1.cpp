#include <bits/stdc++.h>
using namespace std;

string ltrim(const string&);
string rtrim(const string&);



/*
 * Complete the 'reciprocal' function below.
 *
 * The function accepts INTEGER N as parameter.
 */
constexpr int MAX = 10001;
void reciprocal(int N) {
    int table[MAX];
    memset(table, -1, sizeof(table));
    int start, end, cur{ 0 };
    int rest = 1;
    while (1) {
        rest = (rest % N) * 10;
        if (table[rest] != -1) {
            start = table[rest];
            end = cur;
            break;
        }
        table[rest] = cur++;
    }
    rest = (1 % N) * 10;
    cout << "0.";
    for (int i = 0; i < end; ++i) {
        cout << rest / N;
        rest = (rest % N) * 10;
    }
    cout << " ";
    for (int i = start; i < end; ++i) {
        cout << rest / N;
        rest = (rest % N) * 10;
    }
}

int main()
{
    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    reciprocal(N);

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
