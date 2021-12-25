#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;

    vector<int> possible;
    sort(numbers.begin(), numbers.end());
    do {
        for (int i = 0; i < numbers.size(); ++i) {
            possible.emplace_back(stoi(numbers.substr(0, i + 1)));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    sort(possible.begin(), possible.end());
    possible.erase(unique(possible.begin(), possible.end()), possible.end());

    for (int i = 0; i < possible.size(); ++i) {
        if (is_prime(possible[i])) answer++;
    }
    return answer;
}