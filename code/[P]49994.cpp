#include <string>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int solution(string dirs) {
    int answer = 0;
    int x = 5;
    int y = 5;
    int now_d = -1;
    bool visit[11][11][11][11] = { false, };

    for (const auto& d : dirs) {
        if (d == 'R') now_d = 0;
        if (d == 'D') now_d = 1;
        if (d == 'L') now_d = 2;
        if (d == 'U') now_d = 3;
        int nx = x + dx[now_d];
        int ny = y + dy[now_d];
        if (nx < 0 || ny < 0 || nx >= 11 || ny >= 11) continue;

        if (!visit[x][y][nx][ny] == true
            && !visit[nx][ny][x][y] == true) {
            visit[x][y][nx][ny] = visit[nx][ny][x][y] = true;
            ++answer;
        }
        y = ny;
        x = nx;
    }

    return answer;
}