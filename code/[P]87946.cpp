#include <string>
#include <vector>
using namespace std;
bool visit[8] = { false, };

int answer = -1;
void dfs(int cur, int tired, int depth, vector<vector<int>> d) {
    visit[cur] = true;
    tired -= d[cur][1];
    for (int i = 0; i < d.size(); ++i) {
        if (!visit[i] && d[i][0] <= tired) {
            dfs(i, tired, depth + 1, d);
        }
    }
    answer = max(depth, answer);
    visit[cur] = false;
}

int solution(int k, vector<vector<int>> dungeons) {
    for (int i = 0; i < dungeons.size(); ++i) {
        if (k >= dungeons[i][0]) dfs(i, k, 1, dungeons);
    }
    return answer;
}