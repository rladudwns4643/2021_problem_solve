#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int n = numbers.size();
    vector<int> temp(n, 0);
    temp[0] = 1;
    temp[1] = 1;
    sort(numbers.begin(), numbers.end());
    do {
        int add{ 0 };
        for (int i = 0; i < numbers.size(); ++i) {
            if (temp[i] == 1) {
                add += numbers[i];
            }
        }
        answer.emplace_back(add);
    } while (prev_permutation(temp.begin(), temp.end()));

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}