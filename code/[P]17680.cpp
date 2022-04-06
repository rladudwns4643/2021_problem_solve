#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    for (auto it = cities.begin(); it != cities.end(); ++it) {
        transform(it->begin(), it->end(), it->begin(), ::tolower);
        auto a = find(cache.begin(), cache.end(), *it);
        if (a == cache.end()) {
            answer += 5;
            if (cacheSize != 0 && cache.size() >= cacheSize) {
                cache.erase(cache.begin());
            }
            if (cache.size() < cacheSize) {
                cache.push_back(*it);
            }
        }
        else {
            answer += 1;
            cache.erase(a);
            cache.push_back(*it);
        }
    }
    return answer;
}