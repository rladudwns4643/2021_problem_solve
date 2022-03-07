#include <string>
#include <vector>
using namespace std;

typedef long long ll;
vector<pair<ll, ll>> star;
ll len, maxX, maxY, minX, minY;
constexpr ll RANGE = 10000000001; //100000*100000

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    maxX = -RANGE;
    maxY = -RANGE;
    minX = RANGE;
    minY = RANGE;
    len = line.size();

    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            ll adbc = (ll)line[i][0] * line[j][1] - (ll)line[i][1] * line[j][0];
            if (adbc == 0) continue;
            ll bfed = (ll)line[i][1] * line[j][2] - (ll)line[i][2] * line[j][1];
            ll ecaf = (ll)line[i][2] * line[j][0] - (ll)line[i][0] * line[j][2];
            if (bfed % adbc != 0) continue;
            if (ecaf % adbc != 0) continue;
            ll x{ bfed / adbc };
            ll y{ ecaf / adbc };
            star.push_back(make_pair(x, y));
            maxX = max(maxX, x);
            minX = min(minX, x);
            maxY = max(maxY, y);
            minY = min(minY, y);
        }
    }
    ll row = maxY - minY + 1;
    ll col = maxX - minX + 1;
    string t(col, '.');
    answer.assign(row, t);
    for (int i = 0; i < star.size(); ++i) {
        ll x = star[i].first;
        ll y = star[i].second;
        answer[maxY - y][x - minX] = '*';
    }
    return answer;
}