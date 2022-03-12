#include <string>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> solution(int n, ll left, ll right)
{
    vector<int> answer;
    for (ll i = left; i <= right; i++) {
        int row = i / n;
        int col = i % n;
        int k = (row > col) ? row + 1 : col + 1;
        //int k = max(i/n, i%n)+1;
        answer.push_back(k);
    }
    return answer;
}