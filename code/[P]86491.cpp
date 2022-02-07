#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    for (int i = 0; i < sizes.size(); ++i) {
        if (sizes[i][1] > sizes[i][0]) {
            int t = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = t;
        }
    }
    int fMax{ 0 };
    int sMax{ 0 };
    for (int i = 0; i < sizes.size(); ++i) {
        if (sizes[i][0] > fMax) fMax = sizes[i][0];
        if (sizes[i][1] > sMax) sMax = sizes[i][1];
    }
    return fMax * sMax;
}