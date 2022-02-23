#include <string>
#include <vector>

using namespace std;
pair<int, int> dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int get_room_space(const vector<vector<string>>& p, int i) {
    for (int j = 0; j < 5; ++j) {
        for (int k = 0; k < 5; ++k) {
            int cnt{ 0 };
            switch (p[i][j][k]) {
            case 'P': {
                for (int d = 0; d < 4; ++d) {
                    int dx = j + dir[d].first;
                    int dy = k + dir[d].second;
                    if (dx < 0 || dx > 4 || dy < 0 || dy > 4) continue;
                    if (p[i][dx][dy] == 'P') {
                        return 0;
                    }
                }
                break;
            }
            case 'O': {
                for (int d = 0; d < 4; ++d) {
                    int dx = j + dir[d].first;
                    int dy = k + dir[d].second;
                    if (dx < 0 || dx > 4 || dy < 0 || dy > 4) continue;
                    if (p[i][dx][dy] == 'P') {
                        cnt++;
                        if (cnt > 1) {
                            return 0;
                        }
                    }
                }
                break;
            }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < 5; ++i) {
        answer.push_back(get_room_space(places, i));
    }
    return answer;
}