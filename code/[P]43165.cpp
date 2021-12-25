#include <string>
#include <vector>

using namespace std;

int answer = 0;
int solution(vector<int> numbers, int target) {
    if (numbers.size() == 0) {
        if (target == 0) return 1;
        else return 0;
    }
    int next_num = numbers[0];
    numbers.erase(numbers.begin());

    return solution(numbers, target + next_num) + solution(numbers, target - next_num);
}

/*
//dfs
int answer = 0;
void DFS(vector<int>& numbers, int& target, int sum, int n) {
    if (numbers.size() <= n) {
        if (sum == target) ++answer;
        return;
    }
    DFS(numbers, target, sum + numbers[n], n + 1);
    DFS(numbers, target, sum - numbers[n], n + 1);
}
int solution(vector<int> numbers, int target) {

    DFS(numbers, target, numbers[0], 1);
    DFS(numbers, target, -numbers[0], 1);

    return answer;
}
*/

