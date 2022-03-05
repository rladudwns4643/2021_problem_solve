#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

array<array<int, 51>, 51> graph;
int INF = 500001;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for (auto& a : graph) {
        a.fill(INF);
    }
    for (int i = 0; i < road.size(); ++i) {
        graph[road[i][0]][road[i][1]]
            = graph[road[i][1]][road[i][0]]
            = min(graph[road[i][0]][road[i][1]], road[i][2]);
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= N; ++k) {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }

    for (int i = 1; i <= N; ++i) graph[i][i] = 0;
    for (int i = 1; i <= N; ++i) if (graph[1][i] <= K) ++answer;

    return answer;
}