#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<pair<ll,ll>> table;

pair<ll,ll> fibonacci(int n) {
    if (n == 0) {
        return { 1,0 };
    }
    else if (n == 1) {
        return { 0,1 };
    }
    return { table[n - 1].first + table[n - 2].first, table[n - 1].second + table[n - 2].second };
}

int main() {
    for (auto& a : table) {
        a.first = -1;
        a.second = -1;
    }
    int size;
    cin >> size;
    vector<int> input(0, size);
    for (auto& a : input) cin >> a;
    for (int i = 0; i < table.size(); ++i) table[i] = fibonacci(i);
    for (auto a : input) cout << table[a].first << " " << table[a].second << "\n";
}